//
// Created by Administrator on 2026/7/8.
//

#ifndef ALGORITHM_438_H
#define ALGORITHM_438_H

#include "../util.h"

using namespace std;

namespace leetcode438 {
    class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            map<char, int> target;
            for (char c : p) {
                target[c]++;
            }
            map<char, int> cur;
            int l = 0, r = 0, count = 0;
            vector<int> ans;
            while (r < s.size()) {
                char c = s[r++];
                cur[c]++;
                if (target.contains(c) && cur[c] == target[c]) {
                    count++;
                }
                if (count == target.size() && r - l == p.size()) {
                    ans.push_back(l);
                }
                if (r - l == p.size()) {
                    char left = s[l++];
                    if (target.contains(left) && cur[left]-- == target[left]) {
                        count--;
                    }
                }
            }
            return ans;
        }
    };

    void test() {
        Solution solution;
        string s = "abab", p = "ab";
        vector<int> ans = solution.findAnagrams(s, p);
        print(ans);
    }
}

#endif //ALGORITHM_438_H