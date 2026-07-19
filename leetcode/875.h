//
// Created by 10140 on 2026/7/19.
//

#ifndef ALGORITHM_875_H
#define ALGORITHM_875_H

#include "../util.h"
#include <algorithm>

using namespace std;

namespace leetcode875 {
    class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            sort(piles.begin(), piles.end());
            int l = 1, r = piles[piles.size() - 1];
            while (l <= r) {
                int m = l + (r - l) / 2;
                int sum = 0;
                for (int i = 0; i < piles.size(); i++) {
                    sum += piles[i] % m ? piles[i] / m + 1 : piles[i] / m;
                    if (sum > h) {
                        break;
                    }
                }
                if (sum > h) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            return l;
        }
    };

    void test() {
        vector<int> piles{ 30,11,23,4,20 };
        Solution s;
        cout << s.minEatingSpeed(piles, 6) << endl;
    }
}

#endif //ALGORITHM_875_H
