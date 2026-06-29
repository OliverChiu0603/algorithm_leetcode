//
// Created by Administrator on 2026/6/28.
//

#ifndef ALGORITHM_92_H
#define ALGORITHM_92_H

#include "../util.h"

using namespace std;

namespace leetcode92 {
    class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode* dummyNode = new ListNode(0);
            dummyNode->next = head;
            ListNode* p = dummyNode;
            for (int i = 0; i < left - 1; i++) {
                p = p->next;
            }
            ListNode* cur = p->next;
            ListNode* prev = p;
            for (int i = 0; i < right - left + 1; i++) {
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            p->next->next = cur;
            p->next = prev;
            return dummyNode->next;
        }
    };

    void test() {
        Solution s;
        ListNode* head = deserializeList("[1,2,3,4,5]");
        print(s.reverseBetween(head, 2, 4));
    }
}

#endif //ALGORITHM_92_H