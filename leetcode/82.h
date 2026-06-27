//
// Created by Administrator on 2026/6/27.
//

#ifndef ALGORITHM_82_H
#define ALGORITHM_82_H

#include "../util.h"

using namespace std;

namespace leetcode82 {
    class Solution {
    public:
        // 递归解法
        ListNode* deleteDuplicates(ListNode* head) {
            if (head == nullptr || head->next == nullptr) {
                return head;
            }
            if (head->val != head->next->val) {
                head->next = deleteDuplicates(head->next);
                return head;
            }
            while (head->next != nullptr && head->next->val == head->val) {
                head = head->next;
            }
            return deleteDuplicates(head->next);
        }

        ListNode* deleteDuplicates1(ListNode* head) {
            ListNode *dummy = new ListNode(0);
            dummy->next = head;
            ListNode *prev = dummy;
            ListNode *cur = dummy->next;
            while (cur) {
                if (cur->next != nullptr && cur->val == cur->next->val) {
                    while (cur->next && cur->val == cur->next->val) {
                        cur = cur->next;
                    }
                    cur = cur->next;
                    if (cur == nullptr) {
                        prev->next = nullptr;
                    }
                }
                else {
                    prev->next = cur;
                    cur = cur->next;
                    prev = prev->next;
                }
            }
            return dummy->next;
        }
    };

    void test() {
        Solution s;
        ListNode *head = deserializeList("1,2,3,3,4,4,5");
        print(head);
        auto res = s.deleteDuplicates(head);
        print(res);
    }
}

#endif //ALGORITHM_82_H