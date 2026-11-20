# Benchmark

## 环境

- 平台：Windows + MSYS2 UCRT64
- 编译器：g++ 15.2
- 标准：C++17
- 优化：`-O2`

## 实验配置

| 参数 | 值 |
| --- | ---: |
| 随机种子 | 20261116 |
| 操作总数 | 100000 |
| key 空间 | 10000 |
| put 比例 | 20% |
| 淘汰策略 | LRU / FIFO / 随机 |
| 容量 | 10 / 100 / 1000 / 10000 |

## 三策略对照结果

```text
LRU:    capacity=10    gets=80064 hits=92    misses=79972 hit_rate=0.00114908
FIFO:   capacity=10    gets=80064 hits=92    misses=79972 hit_rate=0.00114908
Random: capacity=10    gets=80064 hits=94    misses=79970 hit_rate=0.00117406
LRU:    capacity=100   gets=80064 hits=820   misses=79244 hit_rate=0.0102418
FIFO:   capacity=100   gets=80064 hits=818   misses=79246 hit_rate=0.0102168
Random: capacity=100   gets=80064 hits=826   misses=79238 hit_rate=0.0103167
LRU:    capacity=1000  gets=80064 hits=7806  misses=72258 hit_rate=0.097497
FIFO:   capacity=1000  gets=80064 hits=7817  misses=72247 hit_rate=0.0976344
Random: capacity=1000  gets=80064 hits=7840  misses=72224 hit_rate=0.0979217
LRU:    capacity=10000 gets=80064 hits=45350 misses=34714 hit_rate=0.566422
FIFO:   capacity=10000 gets=80064 hits=45350 misses=34714 hit_rate=0.566422
Random: capacity=10000 gets=80064 hits=45350 misses=34714 hit_rate=0.566422
```

| 容量 | LRU hits | LRU 命中率 | FIFO hits | FIFO 命中率 | 随机 hits | 随机命中率 |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 10 | 92 | 0.00114908 | 92 | 0.00114908 | 94 | 0.00117406 |
| 100 | 820 | 0.0102418 | 818 | 0.0102168 | 826 | 0.0103167 |
| 1000 | 7806 | 0.097497 | 7817 | 0.0976344 | 7840 | 0.0979217 |
| 10000 | 45350 | 0.566422 | 45350 | 0.566422 | 45350 | 0.566422 |

说明：

- `hit_rate = hits / gets`，put 不计入 hit/miss。
- 三种策略复用同一份 workload、同一组容量和相同统计口径。
- 两轮运行结果完全一致。
- 每行均满足 `hits + misses == gets == 80064`。

## 观察与限制

- 容量从 10 增加到 10000 时，三种策略的命中率都明显上升。
- 当前 workload 为均匀随机访问，没有明显热点和访问局部性，三种策略的命中率差异很小；随机淘汰在部分小容量下略高，属于该 workload 下的随机结果，不能证明它优于 LRU。
- 当前结果不能用于判断真实线上环境中哪种淘汰策略更好。要比较策略优劣，需要加入热点访问、周期扫描或冷热混合等更接近真实业务的请求模式。
