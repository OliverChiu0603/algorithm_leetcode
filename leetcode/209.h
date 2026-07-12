//
// Created by Administrator on 2026/7/12.
//

#ifndef ALGORITHM_209_H
#define ALGORITHM_209_H

#include "../util.h"

using namespace std;

namespace leetcode209 {
    class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int curSum = 0, l = 0, r = 0, res = nums.size() + 1;
            while (r < nums.size()) {
                curSum += nums[r];
                while (curSum >= target) {
                    res = min(res, r - l + 1);
                    curSum -= nums[l++];
                }
                r++;
            }
            return res == nums.size() + 1 ? 0 : res;
        }
    };

    void test() {
        Solution s;
        vector<int> nums = {1,4,4};
        cout << s.minSubArrayLen(4, nums) << endl;
    }
}

#endif //ALGORITHM_209_H