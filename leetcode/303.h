//
// Created by Administrator on 2026/7/4.
//

#ifndef ALGORITHM_303_H
#define ALGORITHM_303_H


#include "../util.h"

using namespace std;

namespace leetcode303 {
    class NumArray {
    private:
        vector<int> nums_;
        vector<long> sums_;
    public:
        NumArray(vector<int>& nums) {
            long sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                nums_.push_back(nums[i]);
                sum += nums[i];
                sums_.push_back(sum);
            }
        }

        int sumRange(int left, int right) {
            long l = (left == 0) ? 0 : sums_[left - 1];
            int res = sums_[right] - l;
            return res;
        }
    };

    void test() {
        vector<int> nums = {-2,0,3,-5,2,-1};
        NumArray na(nums);
        cout << na.sumRange(0, 2) << endl;
        cout << na.sumRange(2, 5) << endl;
        cout << na.sumRange(0, 5) << endl;
    }
}

#endif //ALGORITHM_303_H