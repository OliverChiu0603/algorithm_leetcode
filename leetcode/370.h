//
// Created by Administrator on 2026/7/5.
//

#ifndef ALGORITHM_370_H
#define ALGORITHM_370_H

#include "../util.h"

using namespace std;

namespace leetcode370 {
    class Solution {
    public:
        vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
            vector<int> diff (length, 0);
            for (const auto& update : updates) {
                int start = update[0], end = update[1];
                int v = update[2];
                diff[start] += v;
                if (end < length - 1) {
                    diff[end + 1] -= v;
                }
            }
            vector<int> res (length, 0);
            for (int i = 0; i < length; i++) {
                int pre = i == 0 ? 0 : res[i - 1];
                res[i] = pre + diff[i];
            }
            return res;
        }
    };

    void test() {
        Solution s;
        vector<vector<int>> updates = deserializeMatrix("[[1,3,2],[2,4,3],[0,2,-2]]");
        vector<int> res = s.getModifiedArray(5, updates);
        print(res);
    }
}

#endif //ALGORITHM_370_H