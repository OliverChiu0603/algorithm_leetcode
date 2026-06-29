//
// Created by Administrator on 2026/6/28.
//

#ifndef ALGORITHM_445_H
#define ALGORITHM_445_H

#include "../util.h"
#include <stack>

using namespace std;

namespace leetcode445 {
    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            stack<ListNode*> st1;
            stack<ListNode*> st2;
            while (l1 != nullptr) {
                st1.push(l1);
                l1 = l1->next;
            }
            while (l2 != nullptr) {
                st2.push(l2);
                l2 = l2->next;
            }
            int carry = 0;
            stack<ListNode*> st;
            while (!st1.empty() || !st2.empty() || carry > 0) {
                int sum = carry;
                if (!st1.empty()) {
                    sum += st1.top()->val;
                    st1.pop();
                }
                if (!st2.empty()) {
                    sum += st2.top()->val;
                    st2.pop();
                }
                carry = sum / 10;
                st.push(new ListNode(sum % 10));
            }

            ListNode* dummyNode = new ListNode(0);
            ListNode* cur = dummyNode;
            while (!st.empty()) {
                cur->next = st.top();
                st.pop();
                cur = cur->next;
            }
            return dummyNode->next;
        }
    };

    void test() {
        ListNode* l1 = deserializeList("[7,2,4,3]");
        ListNode* l2 = deserializeList("[5,6,4]");
        auto res = Solution().addTwoNumbers(l1, l2);
        print(res);
    }
}


#endif //ALGORITHM_445_H