//
// Created by Administrator on 2026/7/2.
//

#ifndef ALGORITHM_80_H
#define ALGORITHM_80_H

#include "../util.h"

using namespace std;

namespace leetcode80 {
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() <= 2) return nums.size();
            int s = 0, f = 1, count = 1;
            while (f < nums.size()) {
                if (nums[f] == nums[s]) {
                    count++;
                    if (count <= 2) {
                        s++;
                        nums[s] = nums[f];
                    }
                }
                else {
                    s++;
                    nums[s] = nums[f];
                    count = 1;
                }
                f++;
            }
            return s + 1;
        }
    };

    void test() {
        Solution s;
        vector<int> nums = {0,0,1,1,1,1,2,3,3};
        cout << s.removeDuplicates(nums) << endl;
        print(nums);
    }
}

#endif //ALGORITHM_80_H