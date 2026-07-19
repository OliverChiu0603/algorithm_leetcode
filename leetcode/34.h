//
// Created by 10140 on 2026/7/14.
//

#ifndef ALGORITHM_34_H
#define ALGORITHM_34_H

#include "../util.h"

using namespace std;

namespace leetcode34 {
    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int l = 0, r = nums.size();
            int mid = l + (r - l) / 2;
            while (l < r) {
                mid = l + (r - l) / 2;
                if (nums[mid] < target) {
                    l = mid + 1;
                }
                else if (nums[mid] > target) {
                    r = mid;
                }
                else {
                    r = mid;
                }
            }
            if (l >= nums.size() || nums[l] != target) {
                return { -1, -1 };
            }
            vector<int> res;
            res.push_back(l);
            l = 0, r = nums.size(), mid = l + (r - l) / 2;
            while (l < r) {
                mid = l + (r - l) / 2;
                if (nums[mid] < target) {
                    l = mid + 1;
                }
                else if (nums[mid] > target) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            res.push_back(l - 1);
            return res;
        }
    };

    void test() {
        vector<int> nums = { };
        print(Solution().searchRange(nums, 0));
    }
}

#endif //ALGORITHM_34_H
