//
// Created by Administrator on 2026/7/5.
//

#ifndef ALGORITHM_1109_H
#define ALGORITHM_1109_H

#include "../util.h"

using namespace std;

namespace leetcode1109 {
    class Solution {
    public:
        vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
            vector<int> diff(n, 0);
            for (const auto& update : bookings) {
                int start = update[0], end = update[1];
                int seat = update[2];
                diff[start - 1] += seat;
                if (end < n) {
                    diff[end] -= seat;
                }
            }
            for (int i = 1; i < n; i++) {
                diff[i] += diff[i - 1];
            }
            return diff;
        }
    };
}

#endif //ALGORITHM_1109_H