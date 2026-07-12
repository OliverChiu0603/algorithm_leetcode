//
// Created by Administrator on 2026/7/11.
//

#ifndef ALGORITHM_713_H
#define ALGORITHM_713_H

#include "../util.h"

using namespace std;

namespace leetcode713 {
    class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            long long curRes = 1;
            int res = 0;
            int l = 0, r = 0;
            while (r < nums.size()) {
                curRes = curRes * nums[r++];
                while (curRes >= (long long)k) {
                    int left = nums[l++];
                    if (left != 0) {
                        curRes = curRes / left;
                    }
                    else {
                        break;
                    }
                }
                if (curRes < k)
                    res += r - l;
            }
            return res;
        }
    };

    void test() {
        vector<int> nums = {1,2,3};
        int k = 0;
        cout << Solution().numSubarrayProductLessThanK(nums, k) << endl;
    }
}

#endif //ALGORITHM_713_H