//
// Created by Administrator on 2026/6/29.
//

#ifndef ALGORITHM_25_H
#define ALGORITHM_25_H

#include "../util.h"

using namespace std;

namespace leetcode25 {
    class Solution {
    public:
        ListNode* reverseList(ListNode* head, int left, int right) {
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

        ListNode* reverseKGroup(ListNode* head, int k) {
            int len = 0;
            ListNode* temp = head;
            ListNode* dummyNode = new ListNode(0);
            dummyNode->next = head;
            ListNode* pre = dummyNode;
            for (int i = 0; i < k; i++) {
                if (temp == nullptr) {
                    return head;
                }
                temp = temp->next;
                pre = pre->next;
            }
            auto nxt = reverseKGroup(temp, k);
            pre->next = nxt;
            return reverseList(head, 1, k);
        }
    };

    void test() {
        Solution s;
        ListNode* head = deserializeList("[1,2,3,4,5,6,7]");
        auto rs = s.reverseKGroup(head, 3);
        print(rs);
    }
}

#endif //ALGORITHM_25_H