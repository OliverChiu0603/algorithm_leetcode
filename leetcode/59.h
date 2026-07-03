//
// Created by 10140 on 2026/7/2.
//

#ifndef ALGORITHM_59_H
#define ALGORITHM_59_H

#include <cmath>

#include "../util.h"

using namespace std;

namespace leetcode59 {
    class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> matrix(n, vector<int>(n, 0));
            int index = 1;
            for (int iLoop = 0; iLoop < ceil((float)n / 2); iLoop++) {
                for (int i = iLoop; i <= n - iLoop - 1; i++) {
                    matrix[iLoop][i] = index++;
                }
                for (int i = iLoop + 1; i <= n - iLoop - 2; i++) {
                    matrix[i][n - iLoop - 1] = index++;
                }
                if (iLoop < n - iLoop - 1) {
                    for (int i = n - iLoop - 1; i >= iLoop; i--) {
                        matrix[n - iLoop - 1][i] = index++;
                    }
                    for (int i = n - iLoop - 2; i >= iLoop + 1; i--) {
                        matrix[i][iLoop] = index++;
                    }
                }
            }
            return matrix;
        }
    };

    void test() {
        Solution s;
        vector<vector<int>> matrix = s.generateMatrix(3);
        print(matrix);
    }
}

#endif //ALGORITHM_59_H
