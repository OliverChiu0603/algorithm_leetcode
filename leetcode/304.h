//
// Created by Administrator on 2026/7/4.
//

#ifndef ALGORITHM_304_H
#define ALGORITHM_304_H

#include "../util.h"

using namespace std;

namespace leetcode304 {
    class NumMatrix {
        vector<vector<int>> matrix_;
        vector<vector<long long>> sums_;
    public:
        NumMatrix(vector<vector<int>>& matrix) {
            matrix_ = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
            sums_ = vector<vector<long long>>(matrix.size(), vector<long long>(matrix[0].size(), 0));

            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    matrix_[i][j] = matrix[i][j];
                    if (i == 0 && j == 0) {
                        sums_[i][j] = matrix[i][j];
                        continue;
                    }
                    if (i == 0) {
                        sums_[i][j] = sums_[i][j - 1] + matrix_[i][j];
                    }
                    else if (j == 0) {
                        sums_[i][j] = sums_[i - 1][j] + matrix_[i][j];
                    }
                    else {
                        auto leftUp = sums_[i - 1][j - 1];
                        sums_[i][j] = sums_[i - 1][j] - leftUp + sums_[i][j - 1] + matrix_[i][j];
                    }
                }
            }
            print(matrix_);
            print(sums_);
        }

        int sumRegion(int row1, int col1, int row2, int col2) {
            long long leftLow = 0;
            long long rightHigh = 0;
            long long leftHigh = 0;
            long long rightLow = sums_[row2][col2];
            if (col1 > 0) {
                leftLow = sums_[row2][col1 - 1];
            }
            if (row1 > 0) {
                rightHigh = sums_[row1 - 1][col2];
            }
            if (row1 > 0 && col1 > 0) {
                leftHigh = sums_[row1 - 1][col1 - 1];
            }

            long long temp = leftLow - leftHigh;
            return rightLow - rightHigh - temp;
        }
    };

    void test() {
        vector<vector<int>> matrix = deserializeMatrix("[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]");
        NumMatrix nm(matrix);
        cout << nm.sumRegion(2,1,4,3) << endl;
        cout << nm.sumRegion(1,1,2,2) << endl;
        cout << nm.sumRegion(1,2,2,4) << endl;
    }
}

#endif //ALGORITHM_304_H

