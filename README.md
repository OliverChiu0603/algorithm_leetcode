# algorithm_leetcode

个人 LeetCode 算法刷题记录，使用 C++20 实现。

每道题目放在 `leetcode/` 下以题号命名的头文件中，使用独立 `namespace leetcodeXX` 隔离，并提供一个 `test()` 函数用于本地验证。

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
