//
// Created by 10140 on 2026/6/30.
//

#ifndef ALGORITHM_151_H
#define ALGORITHM_151_H

#include "../util.h"

using namespace std;

namespace leetcode151 {
    class Solution {
    public:
        string removeSpace(string s) {
            if (s.empty()) return "";
            int l = 0, r = s.length() - 1;
            while (l < s.size() && s[l] == ' ') l++;
            while (r >= 0 && s[r] == ' ') r--;
            return s.substr(l, r - l + 1);
        }

        string reverseWord(string s) {
            for (int l = 0, r = s.length() - 1; l < r; l++, r--) {
                swap(s[l], s[r]);
            }
            return s;
        }

        string reverseWords(string s) {
            string cleanStr = removeSpace(s);
            string reverseStr = reverseWord(cleanStr);
            int r = 0;
            string cur;
            string res;
            while (r < reverseStr.length()) {
                if (reverseStr[r] == ' ') {
                    if (!cur.empty()) {
                        cur = reverseWord(cur);
                        res += cur;
                        cur.clear();
                        res += " ";
                    }
                }
                else {
                    cur += reverseStr[r];
                }
                r++;
            }
            if (!cur.empty()) {
                cur = reverseWord(cur);
                res += cur;
                cur.clear();
            }
            return res;
        }
    };

    void test() {
        string s = "a good   example";
        cout << Solution().reverseWords(s) << endl;
    }
}

#endif //ALGORITHM_151_H
