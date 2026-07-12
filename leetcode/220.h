//
// Created by Administrator on 2026/7/11.
//

#ifndef ALGORITHM_220_H
#define ALGORITHM_220_H

#include "../util.h"

using namespace std;

namespace leetcode220 {
    class Solution {
    private:
        int getId(int x, long w) {
            return x > 0 ? x / w : (x + 1ll) / w - 1;
        }
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
            unordered_map<int, int> mp;
            for (int i = 0; i < nums.size(); i++) {
                int cur = nums[i];
                int id = getId(cur, valueDiff + 1ll);
                if (mp.find(id) != mp.end()) {
                    return true;
                }
                if (mp.find(id - 1) != mp.end() && abs(cur - mp[id - 1]) <= valueDiff) {
                    return true;
                }
                if (mp.find(id + 1) != mp.end() && abs(cur - mp[id + 1]) <= valueDiff) {
                    return true;
                }
                mp[id] = cur;
                if (i >= indexDiff) {
                    mp.erase(getId(nums[i - indexDiff], valueDiff + 1ll));
                }
            }
            return false;
        }
    };

    // 滑动窗口+暴力解法  超时
    class Solution1 {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
            int l = 0, r = 0;
            while (r < nums.size()) {
                int cur = nums[r];
                while (r - l > indexDiff) {
                    l++;
                }
                for (int i = l; i < r; i++) {
                    int curDiff = abs(cur - nums[i]);
                    if (curDiff <= valueDiff) {
                        return true;
                    }
                }
                r++;
            }
            return false;
        }
    };

    void test() {
        Solution solution;
        vector<int> nums = {1,2,2,3,4,5};
        cout << solution.containsNearbyAlmostDuplicate(nums, 3, 0) << endl;
    }
}

#endif //ALGORITHM_220_H