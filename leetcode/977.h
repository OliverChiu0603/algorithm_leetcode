//
// Created by Administrator on 2026/7/2.
//

#ifndef ALGORITHM_977_H
#define ALGORITHM_977_H

#include "../util.h"

using namespace std;

namespace leetcode977 {
    class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            vector<int> res(nums.size());
            int l = 0, r = nums.size() - 1, cur = nums.size() - 1;
            while (l <= r) {
                if (nums[l] * nums[l] > nums[r] * nums[r]) {
                    res[cur--] = nums[l] * nums[l];
                    l++;
                } else {
                    res[cur--] = nums[r] * nums[r];
                    r--;
                }
            }
            return res;
        }
    };
}

#endif //ALGORITHM_977_H