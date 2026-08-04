//
// Created by OliverChiu on 26-8-4.
//

#ifndef INC_74_H
#define INC_74_H

#include "../util.h"

using namespace std;

namespace leetcode74 {
    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int left = 0, right = matrix.size() * matrix[0].size() - 1;
            int n = matrix[0].size();
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int rowIndex = mid / n;
                int colIndex = mid % n;
                if (matrix[rowIndex][colIndex] == target) {
                    return true;
                }
                else if (matrix[rowIndex][colIndex] < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            return false;
        }
    };

    void test() {
        vector<vector<int>> matrix = deserializeMatrix("[[1,3]]");
        Solution s;
        bool res = s.searchMatrix(matrix, 3);
        cout << res << endl;
    }
}

#endif //INC_74_H
