//
// Created by Administrator on 2026/6/28.
//

#ifndef ALGORITHM_206_H
#define ALGORITHM_206_H

#include "../util.h"

using namespace std;

namespace leetcode206 {
    class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            stack<ListNode*> s;
            while (head) {
                s.push(head);
                head = head->next;
            }
            ListNode* dummyNode = new ListNode(0);
            ListNode* cur = dummyNode;
            while (!s.empty()) {
                cur->next = s.top();
                cur->next->next = nullptr;
                s.pop();
                cur = cur->next;
            }
            return dummyNode->next;
        }
    };

    class Solution1 {
    public:
        ListNode* reverseList(ListNode* head) {
            if (head == nullptr || head->next == nullptr) {
                return head;
            }
            auto temp = head->next;
            auto next = reverseList(head->next);
            head->next = nullptr;
            temp->next = head;
            return next;
        }
    };

    void test() {
        Solution s;
        ListNode* head = deserializeList("[1,2,3,4,5]");
        print(s.reverseList(head));
    }
}

#endif //ALGORITHM_206_H