//
// Created by Administrator on 2026/7/1.
//

#ifndef ALGORITHM_61_H
#define ALGORITHM_61_H

#include "../util.h"

using namespace std;

namespace leetcode61 {
    class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if (head == nullptr || head->next == nullptr) return head;
            ListNode* cur = head;
            int len = 0;
            ListNode* tail = nullptr;
            while (cur) {
                len++;
                if (cur->next == nullptr) {
                    tail = cur;
                }
                cur = cur->next;
            }
            int step = len - (k % len);
            if (step == len) {
                return head;
            }
            ListNode* newHead = new ListNode(0);
            newHead->next = head;
            ListNode* prev = newHead;
            for (int i = 0; i < step; i++) {
                prev = prev->next;
            }
            auto temp = prev->next;
            prev->next = nullptr;
            tail->next = head;
            return temp;
        }
    };

    void test() {
        ListNode* head = deserializeList("[1,2]");
        print(Solution().rotateRight(head, 0));
    }
}

#endif //ALGORITHM_61_H