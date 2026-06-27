# algorithm_leetcode

个人 LeetCode 算法刷题记录，使用 C++20 实现。

## 项目结构

```
.
├── CMakeLists.txt      # CMake 构建配置
├── main.cpp            # 程序入口，调用各题目的 test()
├── util.h              # 公共工具：链表/树节点定义、序列化与打印等
└── leetcode/           # 各题目的解法（按题号命名）
    ├── 19.h            # 19. 删除链表的倒数第 N 个结点
    ├── 21.h            # 21. 合并两个有序链表
    ├── 23.h            # 23. 合并 K 个升序链表
    ├── 86.h            # 86. 分隔链表
    ├── 141.h           # 141. 环形链表
    ├── 142.h           # 142. 环形链表 II
    └── 876.h           # 876. 链表的中间结点
```

每道题目放在 `leetcode/` 下以题号命名的头文件中，使用独立 `namespace leetcodeXX` 隔离，并提供一个 `test()` 函数用于本地验证。

## 题目列表

| 题号 | 题目 | 标签 |
| --- | --- | --- |
| 19 | 删除链表的倒数第 N 个结点 | 链表、双指针 |
| 21 | 合并两个有序链表 | 链表 |
| 23 | 合并 K 个升序链表 | 链表、优先队列 |
| 86 | 分隔链表 | 链表、双指针 |
| 141 | 环形链表 | 链表、快慢指针 |
| 142 | 环形链表 II | 链表、快慢指针 |
| 876 | 链表的中间结点 | 链表、快慢指针 |

## 构建与运行

需要 CMake 与支持 C++20 的编译器。

```bash
cmake -S . -B build
cmake --build build
./build/algorithm        # Windows: .\build\Debug\algorithm.exe
```

在 `main.cpp` 中切换要运行的题目，例如：

```cpp
#include "leetcode/21.h"

int main() {
    leetcode21::test();
    return 0;
}
```
