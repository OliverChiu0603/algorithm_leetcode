//
// Created by OliverChiu on 26-8-4.
//

#ifndef INC_566_H
#define INC_566_H

#include "../util.h"

using namespace std;

namespace leetcode566 {
    class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
            int m = mat.size(), n = mat[0].size();
            if (m * n != r * c) {
                return mat;
            }
            vector<vector<int>> res(r, vector<int>(c));
            int rowIndex = 0, colIndex = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    res[rowIndex][colIndex] = mat[i][j];
                    colIndex++;
                    if (colIndex == c) {
                        colIndex = 0;
                        rowIndex++;
                    }
                }
            }
            return res;
        }
    };
}


#endif //INC_566_H
