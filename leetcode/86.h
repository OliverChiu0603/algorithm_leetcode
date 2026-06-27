//
// Created by Administrator on 2026/6/25.
//

#ifndef ALGORITHM_86_H
#define ALGORITHM_86_H

#include "21.h"
#include "../util.h"

namespace leetcode86 {
    class Solution {
    public:
        ListNode* partition1(ListNode* head, int x) {
            ListNode* less = new ListNode(0), *lessCur = less;;
            ListNode* greater = new ListNode(0), *greaterCur = greater;
            while (head) {
                if (head->val >= x) {
                    greaterCur->next = new ListNode(head->val);
                    head = head->next;
                    greaterCur = greaterCur->next;
                }
                else {
                    lessCur->next = new ListNode(head->val);
                    head = head->next;
                    lessCur = lessCur->next;
                }
            }
            if (less->next == nullptr) {
                return greater->next;
            }
            lessCur->next = greater->next;
            return less->next;
        }

        ListNode* partition(ListNode* head, int x) {
            ListNode* dummy1 = new ListNode(0), *dummy2 = new ListNode(0);
            ListNode* p1 = dummy1, *p2 = dummy2;
            while (head) {
                if (head->val >= x) {
                    p1->next = head;
                    p1 = p1->next;
                }
                else {
                    p2->next = head;
                    p2 = p2->next;
                }
                auto temp = head->next;
                head->next = nullptr;
                head = temp;
            }
            p2->next = dummy1->next;
            return dummy2->next;
        }
    };

    void test() {
        Solution solution;
        ListNode* head = deserializeList("[1,4,3,2,5,2]");
        auto result = solution.partition(head, 3);
        print(result);
    }
}

#endif //ALGORITHM_86_H