//
// Created by Administrator on 2026/7/2.
//

#ifndef ALGORITHM_125_H
#define ALGORITHM_125_H

#include "../util.h"

using namespace std;

namespace leetcode125 {
    class Solution {
    public:
        bool isPalindrome(string s) {
            if (s.empty() || s.size() == 1) return true;
            int l = 0, r = s.size() - 1;
            while (l <= r) {
                while (l < s.size() && !isalnum(s[l])) {
                    l++;
                }
                while (r > 0 && !isalnum(s[r])) {
                    r--;
                }
                if (l >= s.size() || r < 0) return true;
                char cl = tolower(s[l]);
                char cr = tolower(s[r]);
                if (cl != cr) {
                    return false;
                }
                l++;
                r--;
            }
            return true;
        }
    };

    void test() {
        Solution s;
        cout << s.isPalindrome(".,");
    }
}

#endif //ALGORITHM_125_H