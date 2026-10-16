# lru-kv-cache

基于 C++ 的 KV 缓存引擎（LRU 淘汰策略）：哈希表 + 双向链表实现 O(1) 的 get/put，支持文件持久化、benchmark 与命令行交互。

> 寒假实习备战的落地项目，完整计划见 [PLAN.md](PLAN.md)。

## 当前进度

| 周次 | 目标 | 状态 |
| --- | --- | --- |
| 第 1 周 10/16–10/22 | 环境 + C++ 回温 | 进行中 |
| 第 2 周 10/23–10/29 | `get()` 跑通 | 未开始 |
| 第 3 周 10/30–11/5 | `put()` + 淘汰 | 未开始 |
| 第 4 周 11/6–11/12 | 持久化 dump/load | 未开始 |
| 第 5 周 11/13–11/19 | benchmark + 命令行 | 未开始 |
| 第 6 周 11/20–11/26 | README + 八股主攻 | 未开始 |

## 目录结构

```
PLAN.md            备战计划全文
leetcode/          每日一题（文件名：四位题号_英文名.cpp）
src/               项目源码（第 2 周起）
tests/             单元测试
docs/              设计图 / benchmark 数据
```

## 技术栈（计划）

C++17 · CMake · Git · Linux

## 编译运行

项目代码第 2 周起加入，届时补上 CMake 构建方式；当前刷题文件可单独编译：

```bash
g++ -std=c++17 -Wall -Wextra -O2 -o build/two_sum leetcode/0001_two_sum.cpp
```
