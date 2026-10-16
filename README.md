# lru-kv-cache

基于 C++ 的 KV 缓存引擎（LRU 淘汰策略）：哈希表 + 双向链表实现 O(1) 的 get/put，支持文件持久化、benchmark 与命令行交互。

> 寒假实习备战的落地项目，完整计划见 [PLAN.md](PLAN.md)，协作规则见 [AGENTS.md](AGENTS.md)。
> 项目代码与题解由本人独立完成，AI 仅做环境搭建、review、调试与面试模拟。

## 当前进度

| 周次 | 目标 | 状态 |
| --- | --- | --- |
| 启动周末 10/16–10/18 | 查校历 + 环境 + 第 1 题 | 进行中 |
| W1 10/19–10/25 | 双向链表 + 八股起步 | 未开始 |
| W2 10/26–11/01 | \`get()\` 跑通 | 未开始 |
| W3 11/02–11/08 | \`put()\` + 淘汰 | 未开始 |
| W4 11/09–11/15 | 持久化 → **MVD 冻结** | 未开始 |
| W5 11/16–11/22 | 并发（全局 mutex + 4 线程压测）+ 命令行 | 未开始 |
| W6 11/23–11/29 | benchmark + README | 未开始 |
| W7 11/30–12/06 | 简历定稿 + 正式批投递 | 未开始 |

> **MVD（最小可投版本）= CLI + get/put + 淘汰 + 持久化**，W4 结束必须能跑，是简历的保险。

## 目录结构

```
AGENTS.md          协作规则 + 计划全文（agent 读这个）
PLAN.md            备战计划全文（人读版）
leetcode/          每日一题（文件名：四位题号_英文名.cpp）
reference/         参考答案（含 agent 提供的，不算本人产出、不写进简历）
src/               项目源码（第 2 周起）
tests/             单元测试
docs/              设计图 / benchmark 数据 / interview-notes/（面经）/ leetcode-errors.md（错题本）/ progress.md（进度与周报）
```

## 技术栈（计划）

C++17 · CMake · Git · Linux

## 编译运行

项目代码第 2 周起加入，届时补上 CMake 构建方式；当前刷题文件可单独编译：

```bash
g++ -std=c++17 -Wall -Wextra -O2 -o build/two_sum leetcode/0001_two_sum.cpp
```

> VS Code 内：打开任意 `.cpp` 后 **`Ctrl+Shift+B` = 只编译**（产物到 `build/`，不运行）；要看输出就用 Run Task 里的「g++: 编译并运行当前文件」或直接 `F5` 调试。任务定义在 `.vscode/tasks.json`。
> 任务一律用 `type: process`（直接调 g++，不经 PowerShell）——若哪天又看到 `意外的标记"-Command"` 之类的报错，是终端 profile 的参数注入，不要把任务改回 `shell`。
