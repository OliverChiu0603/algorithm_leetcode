//
// Created by Administrator on 2026/7/1.
//

#ifndef ALGORITHM_54_H
#define ALGORITHM_54_H

#include "../util.h"

#include <math.h>

using namespace std;
namespace leetcode54 {
    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            int loop = ceil((float)(min(m, n)) / 2);
            vector<int> res;

            for (int iLoop = 0; iLoop < loop; iLoop++) {
                // 第一行，从左上至右上
                for (int i = iLoop; i <= n - iLoop - 1; i++) {
                    res.push_back(matrix[iLoop][i]);
                }
                // 第二列，从右上至右下
                for (int i = iLoop + 1; i <= m - iLoop - 2; i++) {
                    res.push_back(matrix[i][n - iLoop - 1]);
                }
                // 第三行，从右下至左下
                if (m - iLoop - 1 > iLoop) {
                    for (int i = n - iLoop - 1; i >= iLoop; i--) {
                        res.push_back(matrix[m - iLoop - 1][i]);
                    }
                }

                // 第四列，从左下至左上
                if (iLoop < n - iLoop - 1) {
                    for (int i = m - iLoop - 2; i >= iLoop + 1; i--) {
                        res.push_back(matrix[i][iLoop]);
                    }
                }
            }
            return res;
        }
    };

    void test() {
        vector<vector<int>> matrix = deserializeMatrix("[[1,2,3,4],[5,6,7,8],[9,10,11,12]]");
        Solution s;
        vector<int> res = s.spiralOrder(matrix);
        print(res);
    }
}

#endif //ALGORITHM_54_H