//
// Created by Administrator on 2026/7/12.
//

#ifndef ALGORITHM_395_H
#define ALGORITHM_395_H

#include "../util.h"

using namespace std;

namespace leetcode395 {
    class Solution {
    private:
        int longestSubstring(string s, int k, int count) {
            int l = 0, r = 0, res = 0, validCount = 0;
            map<char, int> mp;
            while (r < s.size()) {
                char cur = s[r++];
                mp[cur]++;
                while (mp.size() > count) {
                    char left = s[l++];
                    if (mp[left]-- == k) {
                        validCount--;
                    }
                    if (mp[left] == 0) {
                        mp.erase(left);
                    }
                }
                if (mp.contains(cur) && mp[cur] == k) {
                    validCount++;
                }
                if (mp.size() == count && validCount == count) {
                    res = max(res, r - l);
                }
            }
            return res;
        }
    public:
        int longestSubstring(string s, int k) {
            int result = 0;
            for (int i = 1; i <= 26; i++) {
                int temp = longestSubstring(s, k, i);
                result = max(result, temp);
            }
            return result;
        }
    };

    void test() {
        Solution s;
        cout << s.longestSubstring("aaabb", 3) << endl;
    }
}

#endif //ALGORITHM_395_H