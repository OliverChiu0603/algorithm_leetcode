//
// Created by Administrator on 2026/7/3.
//

#ifndef ALGORITHM_14_H
#define ALGORITHM_14_H

#include "../util.h"

using namespace std;

namespace leetcode14 {
    class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int index = 0;
            while (true) {
                if (index == strs[0].size()) {
                    return strs[0];
                }
                char c = strs[0][index];
                for (const auto& s : strs) {
                    if (index == s.size()) {
                        return s;
                    }
                    if (s[index] != c) {
                        return s.substr(0, index);
                    }
                }
                index++;
            }
            return strs[0];
        }
    };

    void test() {
        vector<string> strs = {
            "dog","racecar","car"
        };
        Solution s;
        cout << s.longestCommonPrefix(strs) << endl;
    }
}

#endif //ALGORITHM_14_H