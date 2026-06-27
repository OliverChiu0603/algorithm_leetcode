//
// Created by Administrator on 2026/6/28.
//

#ifndef ALGORITHM_378_H
#define ALGORITHM_378_H

#include "../util.h"

#include <vector>

using namespace std;

namespace leetcode378 {
    class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            struct data {
                int val;
                int x;
                int y;

                bool operator>(const data& d) const {
                    return val > d.val;
                }

                data(int v_, int x_, int y_) : val(v_), x(x_), y(y_) {}
            };

            priority_queue<data, vector<data>, greater<data>> pq;

            for (int i = 0; i < matrix.size(); i++) {
                pq.emplace(matrix[i][0], i, 0);
            }

            for (int i = 0; i < k - 1; i++) {
                auto d = pq.top();
                pq.pop();
                if (d.y < matrix.size() - 1) {
                    pq.emplace(matrix[d.x][d.y + 1], d.x, d.y + 1);
                }
            }
            return pq.top().val;
        }
    };


    // 二分查找
    class Solution1 {
    public:
        bool check(const vector<vector<int>>& matrix, int target, int k) {
            int n = matrix.size();
            int m = matrix[0].size();
            int i = n - 1;
            int j = 0;
            int count = 0;
            while (i >= 0 && j < m) {
                if (matrix[i][j] <= target) {
                    j++;
                    count += i + 1;
                }
                else {
                    i--;
                }
            }
            return count >= k;
        }

        int kthSmallest(vector<vector<int>>& matrix, int k) {
            int left = matrix[0][0];
            int n = matrix.size();
            int m = matrix[0].size();
            int right = matrix[n - 1][m - 1];
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (check(matrix, mid, k)) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            return left;
        }
    };

    void test() {
        vector<vector<int>> matrix = deserializeMatrix("[[1,2],[1,3]]");
        Solution s;
        cout << s.kthSmallest(matrix, 3) << endl;
    }
}

#endif //ALGORITHM_378_H