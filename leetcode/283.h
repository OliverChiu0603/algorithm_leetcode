//
// Created by Administrator on 2026/6/29.
//

#ifndef ALGORITHM_283_H
#define ALGORITHM_283_H

#include "../util.h"
#include <vector>

using namespace std;

namespace leetcode283 {
    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            if (nums.empty()) return;
            int s = 0, f = 0;
            while (f < nums.size()) {
                if (nums[f] != 0) {
                    nums[s++] = nums[f];
                }
                f++;
            }
            for (int i = s; i < nums.size(); i++) {
                nums[i] = 0;
            }
        }
    };

    void test() {
        vector<int> nums = {0,1,0,3,12};
        Solution().moveZeroes(nums);
        print(nums);
    }
}

#endif //ALGORITHM_283_H