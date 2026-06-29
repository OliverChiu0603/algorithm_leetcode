//
// Created by Administrator on 2026/6/29.
//

#ifndef ALGORITHM_26_H
#define ALGORITHM_26_H

#include "../util.h"
#include <vector>

using namespace std;

namespace leetcode26 {
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty() || nums.size() == 1) {
                return nums.size();
            }
            int s = 0, f = 0;
            while (f < nums.size()) {
                if (nums[f] != nums[s]) {
                    nums[++s] = nums[f];
                }
                f++;
            }
            return s + 1;
        }
    };

    void test() {
        vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
        Solution s;
        cout << s.removeDuplicates(nums) << endl;
        print(nums);
    }
}

#endif //ALGORITHM_26_H