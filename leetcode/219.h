//
// Created by Administrator on 2026/7/11.
//

#ifndef ALGORITHM_219_H
#define ALGORITHM_219_H

#include "../util.h"

using namespace std;

namespace leetcode219 {
    class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> map;
            int l = 0, r = 0;
            while (r < nums.size()) {
                int cur = nums[r++];
                map[cur]++;
                if (map[cur] > 1) return true;
                while (r - l > k) {
                    map[nums[l++]]--;
                }
            }
            return false;
        }
    };
}

#endif //ALGORITHM_219_H