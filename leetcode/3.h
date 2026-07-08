//
// Created by Administrator on 2026/7/8.
//

#ifndef ALGORITHM_3_H
#define ALGORITHM_3_H

#include "../util.h"

using namespace std;

namespace leetcode3 {
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            map<char, int> occur;
            int res = 0, l = 0, r = 0;
            while (r < s.size()) {
                char c = s[r++];
                occur[c]++;
                while (occur[c] > 1) {
                    char left = s[l++];
                    occur[left]--;
                }
                res = max(res, r - l);
            }
            return res;
        }
    };

    void test() {
        Solution solution;
        string s = " ";
        cout << solution.lengthOfLongestSubstring(s) << endl;
    }
}

#endif //ALGORITHM_3_H