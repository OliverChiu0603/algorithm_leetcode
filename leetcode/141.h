//
// Created by Administrator on 2026/6/27.
//

#ifndef ALGORITHM_141_H
#define ALGORITHM_141_H

#include "../util.h"

namespace leetcode141 {
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode *fast = head, *slow = head;
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow) {
                    return true;
                }
            }
            return false;
        }
    };
}

#endif //ALGORITHM_141_H