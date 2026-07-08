//
// Created by Administrator on 2026/7/5.
//

#ifndef ALGORITHM_1094_H
#define ALGORITHM_1094_H

#include "../util.h"
using namespace std;

namespace leetcode1094 {
    class Solution {
    public:
        bool carPooling(vector<vector<int>>& trips, int capacity) {
            vector<int> diff(1001, 0);
            for (int i = 0; i < trips.size(); i++) {
                int passengers = trips[i][0];
                int start = trips[i][1];
                int end = trips[i][2];
                diff[start] += passengers;
                diff[end] -= passengers;
            }
            for (int i = 0; i < 1001; i++) {
                if (i > 0)
                    diff[i] += diff[i - 1];
                if (diff[i] > capacity)
                    return false;
            }
            return true;
        }
    };
}

#endif //ALGORITHM_1094_H