//
// Created by 10140 on 2026/7/6.
//

#ifndef ALGORITHM_567_H
#define ALGORITHM_567_H

#include "../util.h"

using namespace std;

namespace leetcode567 {
    class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            map<char, int> mp;
            for (auto c : s1) {
                mp[c]++;
            }
            int l = 0, r = 0;
            map<char, int> occurrences;
            int count = 0;
            while (r < s2.size()) {
                char c = s2[r++];
                occurrences[c]++;
                if (!mp.contains(c)) {
                    l = r;
                    occurrences.clear();
                    count = 0;
                    continue;
                }
                if (occurrences[c] == mp[c]) {
                    count++;
                }
                if (count == mp.size()) {
                    return true;
                }
                if (r - l == s1.size()) {
                    if (occurrences[s2[l]] == mp[s2[l]]) {
                        count--;
                    }
                    occurrences[s2[l]]--;
                    l++;
                }
            }
            return false;
        }
    };

    void test() {
        Solution solution;
        string s1 = "ab";
        string s2 = "eidbaooo";
        cout << solution.checkInclusion(s1, s2) << endl;
    }
}

#endif //ALGORITHM_567_H
