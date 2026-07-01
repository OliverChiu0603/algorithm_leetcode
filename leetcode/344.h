//
// Created by 10140 on 2026/6/30.
//

#ifndef ALGORITHM_344_H
#define ALGORITHM_344_H

#include "../util.h"

using namespace std;

namespace leetcode344 {
    class Solution {
    public:
        void reverseString(vector<char>& s) {
            for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
                swap(s[left], s[right]);
            }
        }
    };
}

#endif //ALGORITHM_344_H
