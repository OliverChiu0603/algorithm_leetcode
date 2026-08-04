//
// Created by OliverChiu on 26-8-4.
//

#ifndef INC_410_H
#define INC_410_H

#include "../util.h"

using namespace std;

namespace leetcode410 {
    class Solution {
    public:
        bool canReverse(const vector<int>& nums, int k, int sum) {
            int n = 1;
            int curSum = 0;
            int index = 0;
            while (index < nums.size()) {
                if (sum < nums[index]) {
                    return false;
                }
                if (curSum + nums[index] > sum) {
                    curSum = nums[index];
                    n++;
                }
                else {
                    curSum += nums[index];
                }
                if (n > k) {
                    return false;
                }
                index++;
            }
            return true;
        }

        int splitArray(vector<int>& nums, int k) {
            int sum = 0;
            for (int n : nums) {
                sum += n;
            }
            int left = sum / k, right = sum;
            int mid = left + (right - left) / 2;
            while (left < right) {
                mid = left + (right - left) / 2;
                if (canReverse(nums, k, mid)) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            return left;
        }
    };

    void test() {
        Solution s;
        vector<int> nums = {7,2,5,10,8};
        cout << s.splitArray(nums, 2) << endl;
    }
}

#endif //INC_410_H
