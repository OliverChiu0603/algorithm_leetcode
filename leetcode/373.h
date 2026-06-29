//
// Created by Administrator on 2026/6/28.
//

#ifndef ALGORITHM_373_H
#define ALGORITHM_373_H

#include "../util.h"

using namespace std;

namespace leetcode373 {
    class Solution {
    public:
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<vector<int>> res;
            auto cmp = [&](pair<int, int> a, pair<int, int> b) {
                return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
            };
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
            for (int i = 0; i < min(k, static_cast<int>(nums1.size())); i++) {
                pq.emplace(i, 0);
            }
            for (int i = 0; i < k && !pq.empty(); i++) {
                auto [x, y] = pq.top();
                pq.pop();
                res.emplace_back(vector<int>{nums1[x], nums2[y]});
                if (y < nums2.size() - 1) {
                    pq.emplace(x, y+1);
                }
            }
            return res;
        }
    };

    void test() {
        Solution s;
        vector<int> nums1 { 1,2,4,5,6 };
        print(nums1);
        vector<int> nums2 { 3,5,7,9 };
        print(nums2);
        vector<vector<int>> res = s.kSmallestPairs(nums1, nums2, 3);
        print(res);
    }
}

#endif //ALGORITHM_373_H