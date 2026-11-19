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
| 淘汰策略 | LRU / FIFO |
| 容量 | 10 / 100 / 1000 / 10000 |

## LRU 与 FIFO 对照结果

```text
LRU:  capacity=10    gets=80064 hits=92    misses=79972 hit_rate=0.00114908
FIFO: capacity=10    gets=80064 hits=92    misses=79972 hit_rate=0.00114908
LRU:  capacity=100   gets=80064 hits=820   misses=79244 hit_rate=0.0102418
FIFO: capacity=100   gets=80064 hits=818   misses=79246 hit_rate=0.0102168
LRU:  capacity=1000  gets=80064 hits=7806  misses=72258 hit_rate=0.097497
FIFO: capacity=1000  gets=80064 hits=7817  misses=72247 hit_rate=0.0976344
LRU:  capacity=10000 gets=80064 hits=45350 misses=34714 hit_rate=0.566422
FIFO: capacity=10000 gets=80064 hits=45350 misses=34714 hit_rate=0.566422
```

| 容量 | LRU hits | LRU hit_rate | FIFO hits | FIFO hit_rate |
| ---: | ---: | ---: | ---: | ---: |
| 10 | 92 | 0.00114908 | 92 | 0.00114908 |
| 100 | 820 | 0.0102418 | 818 | 0.0102168 |
| 1000 | 7806 | 0.097497 | 7817 | 0.0976344 |
| 10000 | 45350 | 0.566422 | 45350 | 0.566422 |

说明：

- `hit_rate = hits / gets`，put 不计入 hit/miss。
- 两轮运行结果完全一致。
- 每行均满足 `hits + misses == gets == 80064`。
- 两种策略复用同一份 workload、容量和统计口径。

## 观察与限制

- 容量从 10 增加到 10000 时，两种策略的命中率都明显上升。
- 当前 workload 为均匀随机访问，没有明显热点和访问局部性，因此 LRU 与 FIFO 的命中率非常接近；部分容量下 FIFO 略高属于该 workload 下的正常结果。
- 当前结果不能证明 LRU 优于 FIFO。要比较淘汰策略，需要加入热点访问、周期扫描或冷热混合等更接近真实业务的请求模式。
- 当前尚未实现随机淘汰对照组。
