//
// Created by Administrator on 2026/6/27.
//

#ifndef ALGORITHM_23_H
#define ALGORITHM_23_H

#include <vector>

#include "../util.h"

using namespace std;

namespace leetcode23 {
    class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            struct cmp {
                bool operator()(const ListNode* a, const ListNode* b) const {
                    return a->val > b->val;   // 小顶堆：val 最小的在堆顶
                }
            };
            std::priority_queue<ListNode*, std::vector<ListNode*>, cmp> pq;

            for (auto node : lists) {
                if (node) {
                    pq.push(node);
                }
            }
            ListNode head, *tail = &head;
            while (!pq.empty()) {
                auto node = pq.top();
                pq.pop();
                tail->next = node;
                tail = tail->next;
                if (node->next) {
                    pq.push(node->next);
                }
            }
            return head.next;
        }
    };

    void test() {
        Solution s;
        ListNode* l1 = deserializeList("[1,4,5]");
        ListNode* l2 = deserializeList("[1,3,4]");
        ListNode* l3 = deserializeList("[2,6]");
        vector<ListNode*> params {l1, l2, l3};
        ListNode* result = s.mergeKLists(params);
        print(result);
    }
}

#endif //ALGORITHM_23_H