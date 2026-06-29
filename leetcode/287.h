//
// Created by Administrator on 2026/6/28.
//

#ifndef ALGORITHM_287_H
#define ALGORITHM_287_H

#include <vector>
#include "../util.h"

using namespace std;

namespace leetcode287 {
    class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int slow = 0, fast = 0;
            slow = nums[0];
            fast = nums[nums[0]];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            slow = 0;
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
    };

    void test() {
        Solution s;
        vector<int> nums {1,3,4,2,2};

        print(s.findDuplicate(nums));
    }
}

#endif //ALGORITHM_287_H