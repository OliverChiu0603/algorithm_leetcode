//
// Created by Administrator on 2026/7/2.
//

#ifndef ALGORITHM_75_H
#define ALGORITHM_75_H

#include "../util.h"

using namespace std;

namespace leetcode75 {
    // 双指针
    class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int s = 0, f = nums.size() - 1;
            for (int i = 0; i < f; i++) {
                while (nums[i] == 2 && i <= f) {
                    swap(nums[i], nums[f--]);
                }
                if (nums[i] == 0) {
                    swap(nums[i], nums[s++]);
                }
            }
        }
    };

    // 遍历计数
    class Solution1 {
    public:
        void sortColors(vector<int>& nums) {
            int c0 = 0, c1 = 0, c2 = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    c0++;
                } else if (nums[i] == 1) {
                    c1++;
                } else {
                    c2++;
                }
            }
            for (int i = 0; i < c0; i++) {
                nums[i] = 0;
            }
            for (int i = 0; i < c1; i++) {
                nums[i + c0] = 1;
            }
            for (int i = 0; i < c2; i++) {
                nums[i + c0 + c1] = 2;
            }
        }
    };
}

#endif //ALGORITHM_75_H