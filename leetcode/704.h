//
// Created by 10140 on 2026/7/13.
//

#ifndef ALGORITHM_704_H
#define ALGORITHM_704_H

#include "../util.h"

using namespace std;

namespace leetcode704 {
    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int l = 0, r = nums.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[mid] == target) return mid;
                if (nums[mid] < target) l = mid + 1;
                else r = mid - 1;
            }
            return -1;
        }
    };
}

#endif //ALGORITHM_704_H
