//
// Created by Administrator on 2026/7/8.
//

#ifndef ALGORITHM_1658_H
#define ALGORITHM_1658_H

#include "../util.h"

using namespace std;

namespace leetcode1658 {
    class Solution {
    public:
        int minOperations(vector<int>& nums, int start, int end, int x) {
            int sum = 0;
            for (int num : nums) {
                sum += num;
            }
            int target = sum - x;
            if (target == 0) return nums.size();
            int l = 0, r = 0, res = 0;
            int curSum = 0;
            while (r < nums.size()) {
                curSum += nums[r++];
                while (curSum > target) {
                    curSum -= nums[l++];
                }
                if (curSum == target) {
                    res = max(res, r - l);
                }
            }
            return res == 0 ? -1 : nums.size() - res;
        }

        int minOperations(vector<int>& nums, int x) {
            return minOperations(nums, 0, nums.size() - 1, x);
        }
    };

    void test() {
        Solution s;
        vector<int> nums = {8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309};
        cout << s.minOperations(nums, 134365) << endl;
    }
}

#endif //ALGORITHM_1658_H