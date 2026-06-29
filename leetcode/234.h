//
// Created by Administrator on 2026/6/29.
//

#ifndef ALGORITHM_234_H
#define ALGORITHM_234_H

#include "../util.h"
#include <stack>

using namespace std;

namespace leetcode234 {
    class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            ListNode* fast = head;
            ListNode* slow = head;
            stack<ListNode*> stk;
            while (fast && fast->next) {
                stk.push(slow);
                fast = fast->next->next;
                slow = slow->next;
            }
            if (fast != nullptr) {
                // 奇数个元素
                slow = slow->next;
            }
            while (!stk.empty() && slow != nullptr) {
                auto p = stk.top();
                stk.pop();
                if (p->val != slow->val) {
                    return false;
                }
                slow = slow->next;
            }
            return true;
        }
    };

    void test() {
        Solution s;
        ListNode* head = deserializeList("[1,2]");
        print(s.isPalindrome(head));
    }
}

#endif //ALGORITHM_234_H