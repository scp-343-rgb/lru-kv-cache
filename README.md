# lru-kv-cache

一个基于 C++17 的 KV 缓存引擎：使用 `unordered_map` + 双向链表实现平均 O(1) 的 `get` / `put`，支持容量淘汰、文件持久化、全局互斥锁保护和多线程压测。

项目重点是把数据结构、资源管理、持久化和基础并发放进一个可以实际运行、可以解释清楚的完整程序里。

## 功能

- LRU 淘汰：哈希表负责定位，双向链表维护最近使用顺序
- `get` 命中后将节点移动到链表头部
- `put` 支持新增、更新和容量满时淘汰尾部节点
- 文件持久化：保存当前缓存快照，重启后恢复数据及 LRU 顺序
- 持久化容错：加载时跳过空行、缺少字段、字段过多等非法记录
- 并发访问：使用单一全局 `std::mutex` 保护缓存和链表操作
- 交互式 CLI：支持 `put`、`get`、`save`、`load`、`exit`
- Benchmark：固定随机种子生成 workload，对照 LRU 与 FIFO 在不同容量下的缓存命中率

## 数据结构

```text
unordered_map<string, Node*>
             │
             ▼
[ MRU ] ⇄ ... ⇄ [ LRU ]
   head           tail
```

- `unordered_map`：通过 key 定位节点，平均查找复杂度 O(1)
- 双向链表：维护访问顺序，头部为最近使用，尾部为最久未使用
- 命中 `get`：更新 value，并把节点移动到头部
- 新增 `put`：插入头部；容量已满时先删除尾部节点及哈希表中的对应项

## 请求流程

```text
CLI 输入
   │
   ▼
ThreadSafeLRUCache
   │  lock_guard<mutex>
   ▼
LRUCache
   ├── unordered_map：key -> Node*
   └── 双向链表：维护 MRU → LRU 顺序
```

持久化流程：

```text
dumpFile：链表 MRU → LRU 逐行写入 TSV 文件
loadFile：读取并校验记录，倒序重新 put，恢复原 LRU 顺序
```

持久化格式的详细约束见 [`docs/persistence-format.md`](docs/persistence-format.md)。

## 构建与运行

环境：

- Windows + PowerShell
- MSYS2 UCRT64，`g++` 支持 C++17

在仓库根目录执行：

```powershell
Set-Location D:\lru-kv-cache
.\build.ps1
.\build\kv_cache.exe 3
```

最后一个参数是缓存容量。

示例交互：

```text
put name Alice
OK
put city Beijing
OK
get name
value=Alice
get missing
NOT_FOUND
save cache.tsv
OK
exit
```

重新启动后恢复：

```powershell
.\build\kv_cache.exe 3
```

```text
load cache.tsv
OK
get name
value=Alice
exit
```

## Benchmark

当前 benchmark 使用固定 seed 和固定请求序列，观测不同容量下的命中率。配置为：

- 操作数：100000
- key 空间：10000
- put 比例：20%
- 淘汰策略：LRU / FIFO

| 容量 | LRU 命中率 | FIFO 命中率 |
| ---: | ---: | ---: |
| 10 | 0.114908% | 0.114908% |
| 100 | 1.02418% | 1.02168% |
| 1000 | 9.7497% | 9.76344% |
| 10000 | 56.6422% | 56.6422% |

两轮运行结果一致，所有结果均满足 `hits + misses == gets`。当前 workload 为均匀随机访问，不能据此证明 LRU 优于 FIFO；完整配置和逐项数据见 [`docs/benchmark.md`](docs/benchmark.md)。

编译并运行 benchmark：

```powershell
C:/msys64/ucrt64/bin/g++.exe -std=c++17 -Wall -Wextra -O2 -I src src/list.cpp src/lru_cache.cpp src/Fifo_cache.cpp tests/benchmark.cpp -o build/benchmark.exe
.\build\benchmark.exe
```

## 并发压测

`tests/thread_stress.cpp` 使用 4 个线程执行混合 `get` / `put` 操作。当前本地单次运行结果：

```text
operations=2000000 seconds=0.167454 qps=1.19436e+07
```

该数字依赖机器、编译器和运行状态，仅作为本地压测记录，不代表通用性能结论。

编译并运行：

```powershell
C:/msys64/ucrt64/bin/g++.exe -std=c++17 -Wall -Wextra -O2 -I src src/list.cpp src/lru_cache.cpp src/thread_safe.cpp tests/thread_stress.cpp -o build/thread_stress.exe
.\build\thread_stress.exe
```

## 目录结构

```text
src/
  list.h / list.cpp              双向链表
  lru_cache.h / lru_cache.cpp    LRU 缓存核心逻辑
  Fifo_cache.h / Fifo_cache.cpp  FIFO benchmark 对照组
  persistence.cpp                文件保存与加载
  thread_safe.h / thread_safe.cpp
  main.cpp                       交互式 CLI
tests/
  benchmark.cpp                  固定 workload 的命中率测试
  thread_stress.cpp              4 线程混合读写压测
  manual_*.cpp                   手动回归测试
docs/
  benchmark.md                   benchmark 配置与结果
  persistence-format.md          持久化文件格式
```

## 当前限制

- 使用单一全局 mutex，所有读写操作串行化；后续可按哈希分桶扩展分段锁
- 持久化是完整快照，暂未实现写临时文件后原子替换、WAL 或崩溃恢复
- 持久化格式中的 key/value 暂不支持 TAB 和换行
- 当前 benchmark 使用均匀随机访问，未覆盖真实业务中的热点数据和访问倾斜
- 暂未加入 CMake 和自动化测试框架，当前通过构建脚本及手动回归程序验证

## 后续方向

- 按哈希分桶实现分段锁，降低不同 key 之间的锁竞争
- 增加随机淘汰对照，并加入热点访问等更接近真实业务的 workload
- 为持久化增加原子写入和恢复校验
- 增加更接近热点访问、周期性扫描等场景的 benchmark
