//
// Created by 10140 on 2026/7/19.
//

#ifndef ALGORITHM_1011_H
#define ALGORITHM_1011_H

#include "../util.h"

using namespace std;

namespace leetcode1011 {
    class Solution {
    public:
        int shipWithinDays(vector<int>& weights, int days) {
            int sum = 0;
            for (int weight : weights) {
                sum += weight;
            }
            int l = 1, r = sum;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int daysConsumed = 0;
                int curWeight = 0;
                bool invalid = false;
                for (int i = 0; i < weights.size(); i++) {
                    int w = weights[i];
                    if (w > mid) {
                        invalid = true;
                        break;
                    }
                    curWeight += w;
                    if (curWeight > mid) {
                        daysConsumed++;
                        curWeight = w;
                    }
                    if (i == weights.size() - 1) {
                        daysConsumed++;
                    }
                    if (daysConsumed > days) {
                        invalid = true;
                        break;
                    }
                }
                if (invalid) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            return l;
        }
    };

    void test() {
        Solution s;
        vector<int> weights = { 1,2,3,1,1 };
        cout << s.shipWithinDays(weights, 4) << endl;
    }
}

#endif //ALGORITHM_1011_H
