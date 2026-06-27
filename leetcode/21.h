//
// Created by Administrator on 2026/6/25.
//

#ifndef ALGORITHM_21_H
#define ALGORITHM_21_H

#include "../util.h"

namespace leetcode21 {
    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode *dummy = new ListNode(-1);
            ListNode *temp = dummy;
            while (list1 || list2) {
                if (list1 && list2) {
                    if (list1->val <= list2->val) {
                        temp->next = list1;
                        list1 = list1->next;
                    }
                    else {
                        temp->next = list2;
                        list2 = list2->next;
                    }
                }
                else if (list1 == nullptr) {
                    temp->next = list2;
                    list2 = list2->next;
                }
                else {
                    temp->next = list1;
                    list1 = list1->next;
                }
                temp = temp->next;
            }
            return dummy->next;
        }
    };

    void test() {
        Solution solution;
        ListNode *list1 = deserializeList("[1,2,4]");
        ListNode *list2 = deserializeList("[1,3,4]");
        auto result = solution.mergeTwoLists(list1, list2);

        print(result);
    }
}

#endif //ALGORITHM_21_H