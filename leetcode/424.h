//
// Created by Administrator on 2026/7/11.
//

#ifndef ALGORITHM_424_H
#define ALGORITHM_424_H

#include "../util.h"

using namespace std;

namespace leetcode424 {
    class Solution {
    public:
        int characterReplacement(string s, int k) {
            int maxCount = 0;
            vector<int> charTimes(26, 0);
            int l = 0, r = 0, res = 0;
            while (r < s.size()) {
                int c = s[r++] - 'A';
                charTimes[c]++;
                if (charTimes[c] > maxCount) {
                    maxCount = charTimes[c];
                }
                while (r - l - maxCount > k) {
                    charTimes[s[l++] - 'A']--;
                }
                res = max(res, r - l);
            }
            return res;
        }
    };

    void test() {
        Solution s;
        cout << s.characterReplacement("AABABBA", 1) << endl;
    }
}

#endif //ALGORITHM_424_H