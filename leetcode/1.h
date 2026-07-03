//
// Created by Administrator on 2026/7/3.
//

#ifndef ALGORITHM_1_H
#define ALGORITHM_1_H

#include "../util.h"
using namespace std;

namespace leetcode1 {
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> indexMap;
            for (int i = 0; i < nums.size(); i++) {
                int extra =  target - nums[i];
                if (indexMap.find(extra) != indexMap.end()) {
                    return {i, indexMap[extra]};
                }
                indexMap[nums[i]] = i;
            }
            return {};
        }
    };
}

#endif //ALGORITHM_1_H