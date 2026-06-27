//
// Created by Administrator on 2026/6/27.
//

#ifndef ALGORITHM_876_H
#define ALGORITHM_876_H

#include "../util.h"

using namespace std;

namespace leetcode876 {
    class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode *fast = head, *slow = head;
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }
    };

    void test() {
        Solution s;
        ListNode *head = deserializeList("[1,2,3,4,5]");
        auto result = s.middleNode(head);
        print(result);
    }
}

#endif //ALGORITHM_876_H