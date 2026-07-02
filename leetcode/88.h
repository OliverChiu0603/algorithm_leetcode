//
// Created by Administrator on 2026/7/2.
//

#ifndef ALGORITHM_88_H
#define ALGORITHM_88_H

#include "../util.h"

using namespace std;

namespace leetcode88 {
    class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1, j = n - 1, cur = m + n - 1;
            while (i >= 0 || j >= 0) {
                if (i >= 0 && j >= 0) {
                    if (nums1[i] > nums2[j]) {
                        nums1[cur--] = nums1[i--];
                    } else {
                        nums1[cur--] = nums2[j--];
                    }
                } else if (i < 0) {
                    nums1[cur--] = nums2[j--];
                } else {
                    nums1[cur--] = nums1[i--];
                }
            }
        }
    };

    void test() {
        vector<int> nums1 = {0};
        int m = 0, n = 1;
        vector<int> nums2 = {1};
        Solution solution;
        solution.merge(nums1, m, nums2, n);
        print(nums1);
    }
}

#endif //ALGORITHM_88_H