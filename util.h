//
// Created by Administrator on 2026/6/25.
//

#ifndef ALGORITHM_UTIL_H
#define ALGORITHM_UTIL_H

#include <array>
#include <cctype>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

namespace util_detail {
    inline std::string trim(const std::string &s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;
        while (left <= right && std::isspace(static_cast<unsigned char>(s[left]))) {
            ++left;
        }
        while (left <= right && std::isspace(static_cast<unsigned char>(s[right]))) {
            --right;
        }
        return left > right ? "" : s.substr(left, right - left + 1);
    }

    inline std::vector<std::string> splitValues(std::string data) {
        data = trim(data);
        if (!data.empty() && data.front() == '[') {
            data.erase(data.begin());
        }
        if (!data.empty() && data.back() == ']') {
            data.pop_back();
        }

        std::vector<std::string> values;
        std::stringstream ss(data);
        std::string token;
        while (std::getline(ss, token, ',')) {
            token = trim(token);
            if (!token.empty()) {
                values.push_back(token);
            }
        }
        return values;
    }

    inline bool isNullToken(const std::string &s) {
        return s == "null" || s == "NULL" || s == "#";
    }
}

inline std::string serializeList(const ListNode *head) {
    std::string result = "[";
    for (const ListNode *cur = head; cur != nullptr; cur = cur->next) {
        if (cur != head) {
            result += ",";
        }
        result += std::to_string(cur->val);
    }
    result += "]";
    return result;
}

inline ListNode *deserializeList(const std::string &data) {
    std::vector<std::string> values = util_detail::splitValues(data);
    ListNode dummy;
    ListNode *tail = &dummy;

    for (const std::string &value: values) {
        tail->next = new ListNode(std::stoi(value));
        tail = tail->next;
    }
    return dummy.next;
}

// 把形如 "[1,2,3]" 的字符串解析成一维数组；兼容空白字符，"[]" 解析为空数组。
inline std::vector<int> deserializeArray(const std::string &data) {
    std::vector<int> nums;
    for (const std::string &value: util_detail::splitValues(data)) {
        nums.push_back(std::stoi(value));
    }
    return nums;
}

inline std::string serializeTree(const TreeNode *root) {
    if (root == nullptr) {
        return "[]";
    }

    std::vector<std::string> values;
    std::queue<const TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        const TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
            values.push_back("null");
            continue;
        }

        values.push_back(std::to_string(node->val));
        q.push(node->left);
        q.push(node->right);
    }

    while (!values.empty() && values.back() == "null") {
        values.pop_back();
    }

    std::string result = "[";
    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        if (i > 0) {
            result += ",";
        }
        result += values[i];
    }
    result += "]";
    return result;
}

inline TreeNode *deserializeTree(const std::string &data) {
    std::vector<std::string> values = util_detail::splitValues(data);
    if (values.empty() || util_detail::isNullToken(values[0])) {
        return nullptr;
    }

    TreeNode *root = new TreeNode(std::stoi(values[0]));
    std::queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < static_cast<int>(values.size())) {
        TreeNode *node = q.front();
        q.pop();

        if (i < static_cast<int>(values.size()) && !util_detail::isNullToken(values[i])) {
            node->left = new TreeNode(std::stoi(values[i]));
            q.push(node->left);
        }
        ++i;

        if (i < static_cast<int>(values.size()) && !util_detail::isNullToken(values[i])) {
            node->right = new TreeNode(std::stoi(values[i]));
            q.push(node->right);
        }
        ++i;
    }

    return root;
}

// 把二维矩阵序列化成形如 "[[1,5,9],[10,11,13],[12,13,15]]" 的字符串。
inline std::string serializeMatrix(const std::vector<std::vector<int>> &matrix) {
    std::string result = "[";
    for (std::size_t i = 0; i < matrix.size(); ++i) {
        if (i > 0) {
            result += ",";
        }
        result += "[";
        for (std::size_t j = 0; j < matrix[i].size(); ++j) {
            if (j > 0) {
                result += ",";
            }
            result += std::to_string(matrix[i][j]);
        }
        result += "]";
    }
    result += "]";
    return result;
}

// 把形如 "[[1,5,9],[10,11,13],[12,13,15]]" 的字符串解析回二维矩阵。
// 兼容空白字符；"[]" 解析为空矩阵，"[[]]" 解析为含一个空行的矩阵。
inline std::vector<std::vector<int>> deserializeMatrix(const std::string &data) {
    std::string s = util_detail::trim(data);
    // 去掉最外层的方括号，剩下若干个 "[...]" 行（行之间以逗号分隔）。
    if (!s.empty() && s.front() == '[') {
        s.erase(s.begin());
    }
    if (!s.empty() && s.back() == ']') {
        s.pop_back();
    }

    std::vector<std::vector<int>> matrix;
    std::string row;
    bool inRow = false;
    for (char c: s) {
        if (c == '[') {
            row.clear();
            inRow = true;
        } else if (c == ']') {
            inRow = false;
            std::vector<int> nums;
            for (const std::string &token: util_detail::splitValues(row)) {
                nums.push_back(std::stoi(token));
            }
            matrix.push_back(nums);
        } else if (inRow) {
            row += c;
        }
        // 行与行之间的逗号、空白字符等都被忽略。
    }
    return matrix;
}

namespace util_detail {
    template<typename T>
    void printValue(const T &value);

    template<typename First, typename Second>
    void printValue(const std::pair<First, Second> &value);

    template<typename T, std::size_t N>
    void printValue(const std::array<T, N> &value);

    template<typename T>
    void printValue(const std::vector<T> &value);

    template<typename T>
    void printValue(const std::deque<T> &value);

    template<typename T>
    void printValue(const std::list<T> &value);

    template<typename T>
    void printValue(const std::set<T> &value);

    template<typename T>
    void printValue(const std::unordered_set<T> &value);

    template<typename Key, typename Value>
    void printValue(const std::map<Key, Value> &value);

    template<typename Key, typename Value>
    void printValue(const std::unordered_map<Key, Value> &value);

    template<typename T, typename Container>
    void printValue(std::queue<T, Container> value);

    template<typename T, typename Container>
    void printValue(std::stack<T, Container> value);

    template<typename T, typename Container, typename Compare>
    void printValue(std::priority_queue<T, Container, Compare> value);

    inline void printValue(const std::string &value) {
        std::cout << value;
    }

    inline void printValue(const char *value) {
        std::cout << (value == nullptr ? "null" : value);
    }

    inline void printValue(char *value) {
        std::cout << (value == nullptr ? "null" : value);
    }

    inline void printValue(char value) {
        std::cout << value;
    }

    inline void printValue(bool value) {
        std::cout << (value ? "true" : "false");
    }

    inline void printValue(ListNode *head) {
        std::cout << serializeList(head);
    }

    inline void printValue(const ListNode *head) {
        std::cout << serializeList(head);
    }

    inline void printValue(TreeNode *root) {
        std::cout << serializeTree(root);
    }

    inline void printValue(const TreeNode *root) {
        std::cout << serializeTree(root);
    }

    template<typename Container>
    void printSequence(const Container &container, char left = '[', char right = ']') {
        std::cout << left;
        bool first = true;
        for (const auto &value: container) {
            if (!first) {
                std::cout << ",";
            }
            first = false;
            printValue(value);
        }
        std::cout << right;
    }

    template<typename T, std::size_t N>
    void printValue(const std::array<T, N> &value) {
        printSequence(value);
    }

    template<typename T>
    void printValue(const std::vector<T> &value) {
        printSequence(value);
    }

    template<typename T>
    void printValue(const std::deque<T> &value) {
        printSequence(value);
    }

    template<typename T>
    void printValue(const std::list<T> &value) {
        printSequence(value);
    }

    template<typename T>
    void printValue(const std::set<T> &value) {
        printSequence(value, '{', '}');
    }

    template<typename T>
    void printValue(const std::unordered_set<T> &value) {
        printSequence(value, '{', '}');
    }

    template<typename Key, typename Value>
    void printValue(const std::map<Key, Value> &value) {
        printSequence(value, '{', '}');
    }

    template<typename Key, typename Value>
    void printValue(const std::unordered_map<Key, Value> &value) {
        printSequence(value, '{', '}');
    }

    template<typename T, typename Container>
    void printValue(std::queue<T, Container> value) {
        std::cout << "[";
        bool first = true;
        while (!value.empty()) {
            if (!first) {
                std::cout << ",";
            }
            first = false;
            printValue(value.front());
            value.pop();
        }
        std::cout << "]";
    }

    template<typename T, typename Container>
    void printValue(std::stack<T, Container> value) {
        std::cout << "[";
        bool first = true;
        while (!value.empty()) {
            if (!first) {
                std::cout << ",";
            }
            first = false;
            printValue(value.top());
            value.pop();
        }
        std::cout << "]";
    }

    template<typename T, typename Container, typename Compare>
    void printValue(std::priority_queue<T, Container, Compare> value) {
        std::cout << "[";
        bool first = true;
        while (!value.empty()) {
            if (!first) {
                std::cout << ",";
            }
            first = false;
            printValue(value.top());
            value.pop();
        }
        std::cout << "]";
    }

    template<typename First, typename Second>
    void printValue(const std::pair<First, Second> &value) {
        std::cout << "{";
        printValue(value.first);
        std::cout << ":";
        printValue(value.second);
        std::cout << "}";
    }

    template<typename T>
    void printValue(const T &value) {
        std::cout << value;
    }
}

template<typename T>
inline void print(const T &value) {
    util_detail::printValue(value);
    std::cout << std::endl;
}

inline void print(ListNode *head) {
    util_detail::printValue(head);
    std::cout << std::endl;
}

inline void print(const ListNode *head) {
    util_detail::printValue(head);
    std::cout << std::endl;
}

inline void print(TreeNode *root) {
    util_detail::printValue(root);
    std::cout << std::endl;
}

inline void print(const TreeNode *root) {
    util_detail::printValue(root);
    std::cout << std::endl;
}

#endif //ALGORITHM_UTIL_H
