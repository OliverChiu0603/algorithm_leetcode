//
// Created by Administrator on 2026/6/29.
//

#ifndef ALGORITHM_27_H
#define ALGORITHM_27_H

#include "../util.h"
#include <vector>

using namespace std;

namespace leetcode27 {
    class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            if (nums.empty()) return 0;
            int s = 0, f = 0;
            while (f < nums.size()) {
                if (nums[f] != val) {
                    nums[s++] = nums[f];
                }
                f++;
            }
            return s;
        }
    };

    void test() {
        vector<int> nums = {3,2,2,3};
        Solution s;
        cout << s.removeElement(nums, 3) << endl;
        print(nums);
    }
}

#endif //ALGORITHM_27_H