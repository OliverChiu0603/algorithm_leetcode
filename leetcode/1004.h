//
// Created by Administrator on 2026/7/11.
//

#ifndef ALGORITHM_1004_H
#define ALGORITHM_1004_H

#include "../util.h"

using namespace std;

namespace leetcode1004 {
    class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int windowOneCount = 0;
            int l = 0, r = 0, res = 0;
            while (r < nums.size()) {
                if (nums[r++] == 1) {
                    windowOneCount++;
                }
                while (r - l - windowOneCount > k) {
                    if (nums[l++] == 1) {
                        windowOneCount--;
                    }
                }
                res = max(res, r - l);
            }
            return res;
        }
    };

    void test() {
        Solution s;
        vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        int k = 3;
        cout << s.longestOnes(nums, k) << endl;
    }
}

#endif //ALGORITHM_1004_H