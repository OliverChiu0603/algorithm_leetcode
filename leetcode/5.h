//
// Created by 10140 on 2026/6/30.
//

#ifndef ALGORITHM_5_H
#define ALGORITHM_5_H

#include "../util.h"

using namespace std;

namespace leetcode5 {
    class Solution {
    public:
        string getPalindrome(string s, int l, int r) {
            while (l >= 0 && r <= s.size() && s[l] == s[r]) {
                l--;
                r++;
            }
            return s.substr(l + 1, r - l - 1);
        };

        string longestPalindrome(string s) {
            string res = "";
            for (int i = 0; i < s.size(); i++) {
                string s1 = getPalindrome(s, i, i);
                res = s1.size() > res.size() ? s1 : res;
                if (i < s.size() - 1) {
                    string s2 = getPalindrome(s, i, i + 1);
                    res = s2.size() > res.size() ? s2 : res;
                }
            }
            return res;
        }
    };

    void test() {
        Solution s;
        string str = "cbbd";
        cout << s.longestPalindrome(str) << endl;
    }
}

#endif //ALGORITHM_5_H
