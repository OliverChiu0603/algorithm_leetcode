//
// Created by Administrator on 2026/6/27.
//

#ifndef ALGORITHM_19_H
#define ALGORITHM_19_H

#include "../util.h"

namespace leetcode19 {
    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (head == nullptr) return nullptr;
            ListNode *dummyNode = new ListNode(0);
            dummyNode->next = head;
            ListNode *fast = dummyNode, *slow = dummyNode;
            while (n-- > 0) {
                fast = fast->next;
            }
            while (fast->next) {
                fast = fast->next;
                slow = slow->next;
            }
            if (slow->next != nullptr) {
                slow->next = slow->next->next;
            }
            return dummyNode->next;
        }


        ListNode* removeNthFromEnd1(ListNode* head, int n) {
            if (head == NULL) return NULL;
            int len = 0;
            ListNode *temp = head;
            while (temp != NULL) {
                len++;
                temp = temp->next;
            }
            ListNode *newHead = new ListNode(0);
            newHead->next = head;
            int left = len - n;
            temp = newHead;
            while (left-- > 0) {
                temp = temp->next;
            }
            if (temp->next != nullptr)
                temp->next = temp->next->next;
            return newHead->next;
        }
    };

    void test() {
        Solution s;
        ListNode *head = deserializeList("[1,2,3,4,5]");
        auto res = s.removeNthFromEnd(head, 2);
        print(res);
    }
}

#endif //ALGORITHM_19_H