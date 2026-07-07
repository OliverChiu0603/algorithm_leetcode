//
// Created by 10140 on 2026/7/6.
//

#ifndef ALGORITHM_76_H
#define ALGORITHM_76_H

#include "../util.h"

using namespace std;

namespace leetcode76 {
    class Solution {
    public:
        string minWindow(string s, string t) {
            map<char, int> mp;
            for (char c : t) {
                mp[c]++;
            }
            int l = 0, r = 0, count = 0;
            map<char, int> occur;
            string res;
            while (r < s.size()) {
                char cur = s[r++];
                occur[cur]++;
                if (mp.contains(cur) && occur[cur] == mp[cur]) {
                    count++;
                }
                while (count == mp.size()) {
                string curStr = s.substr(l, r - l);
                    if (res.empty() || curStr.size() < res.size()) {
                        res = s.substr(l, r - l);
                    }

                    char left = s[l++];
                    occur[left]--;
                    if (mp.contains(left) && occur[left] < mp[left]) {
                        count--;
                    }
                }
            }
            return res;
        }
    };

    void test() {
        Solution solution;
        string s = "a";
        string t = "aa";
        cout << solution.minWindow(s, t);
    }
}

#endif //ALGORITHM_76_H
