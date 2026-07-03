//
// Created by Administrator on 2026/7/3.
//

#ifndef ALGORITHM_15_H
#define ALGORITHM_15_H

#include <algorithm>

#include "../util.h"

using namespace std;

namespace leetcode15 {
    class Solution {
    public:
        vector<vector<int>> getTwoSum(const vector<int>& nums, int start, int target) {
            vector<vector<int>> res;
            int l = start, r = nums.size() - 1;
            while (l < r) {
                int left = nums[l];
                int right = nums[r];
                int sum = left + right;
                if (sum == target) {
                    res.push_back({left, right});
                    while (l < r && nums[l] == left) {
                        l++;
                    }
                    while (l < r && nums[r] == right) {
                        r--;
                    }
                }
                else if (sum < target) {
                    while (l < r && nums[l] == left) {
                        l++;
                    }
                }
                else {
                    while (l < r && nums[r] == right) {
                        r--;
                    }
                }
            }
            return res;
        }

        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            for (int i = 0; i < nums.size() - 2; ) {
                int target = -nums[i];
                vector<vector<int>> resTemp = getTwoSum(nums, i + 1, target);
                if (!resTemp.empty()) {
                    for (const vector<int>& v : resTemp) {
                        res.push_back(vector<int>{nums[i], v[0], v[1]});
                    }
                }
                i++;
                while (i < nums.size() - 2 && nums[i] == -target) {
                    i++;
                }
            }
            return res;
        }
    };

    void test() {
        Solution s;
        vector<int> nums = {-1,0,1,2,-1,-4};
        auto res = s.threeSum(nums);
        print(res);
    }
}

#endif //ALGORITHM_15_H