//
// Created by Administrator on 2026/6/28.
//

#ifndef ALGORITHM_2_H
#define ALGORITHM_2_H

#include "../util.h"

using namespace std;

namespace leetcode2 {
    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummyNode = new ListNode(0);
            ListNode *cur = dummyNode;
            int flag = 0;
            while (l1 || l2) {
                int num1 = l1 ? l1->val : 0;
                int num2 = l2 ? l2->val : 0;
                int sum = num1 + num2 + flag;
                cur->next = new ListNode(sum % 10);
                cur = cur->next;
                flag = sum / 10;
                if (l1) l1 = l1->next;
                if (l2) l2 = l2->next;
            }
            if (flag) cur->next = new ListNode(1);
            return dummyNode->next;
        }
    };

    void test() {
        Solution s;
        ListNode* l1 = deserializeList("[2,4,3]");
        ListNode* l2 = deserializeList("[5,6,4]");
        auto res = s.addTwoNumbers(l1, l2);
        print(res);
    }
}

#endif //ALGORITHM_2_H