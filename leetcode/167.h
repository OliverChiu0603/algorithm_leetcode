//
// Created by 10140 on 2026/6/30.
//

#ifndef ALGORITHM_167_H
#define ALGORITHM_167_H

#include "../util.h"

using namespace std;

namespace leetcode167 {
    class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            if (numbers.size() < 2) return {};
            int left = 0, right = numbers.size() - 1;
            while (left < right) {
                int sum = numbers[left] + numbers[right];
                if (sum > target) {
                    right--;
                }
                else if (sum < target) {
                    left++;
                } else {
                    break;
                }
            }
            return vector<int>{left + 1, right + 1};
        }
    };

    void test() {
        vector<int> input{2,7,11,15};
        Solution s;
        vector<int> result = s.twoSum(input, 9);
        print(result);
    }
}

#endif //ALGORITHM_167_H
