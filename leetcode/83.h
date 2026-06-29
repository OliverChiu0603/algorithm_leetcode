//
// Created by Administrator on 2026/6/29.
//

#ifndef ALGORITHM_83_H
#define ALGORITHM_83_H

#include "../util.h"

using namespace std;

namespace leetcode83 {
    class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if (!head || !head->next) return head;
            ListNode* dummy = new ListNode(-101);
            dummy->next = head;
            ListNode* s = dummy, *f = head;
            while (f) {
                auto next = f->next;
                if (f->val != s->val) {
                    f->next = nullptr;
                    s->next = f;
                    s = s->next;
                }
                f = next;
            }
            return head;
        }
    };

    void test() {
        ListNode* head = deserializeList("[1,1]");
        print(Solution().deleteDuplicates(head));
    }
}

#endif //ALGORITHM_83_H