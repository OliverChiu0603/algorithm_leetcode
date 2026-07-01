//
// Created by 10140 on 2026/6/30.
//

#ifndef ALGORITHM_48_H
#define ALGORITHM_48_H

#include <ranges>

#include "../util.h"

using namespace std;

namespace leetcode48 {
    class Solution {
    public:
        void reverse(vector<int>& nums) {
            for (int l = 0, r = nums.size() - 1; l < r; l++, r--) {
                swap(nums[l], nums[r]);
            }
        }

        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            for (int i = 0; i < n; i++) {
                reverse(matrix[i]);
            }
        }
    };

    void test() {
        Solution s;
        vector<vector<int>> matrix = deserializeMatrix("[[1,2,3],[4,5,6],[7,8,9]]");
        s.rotate(matrix);
        print(matrix);
    }
}

#endif //ALGORITHM_48_H
