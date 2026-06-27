//
// Created by Administrator on 2026/6/27.
//

#ifndef ALGORITHM_160_H
#define ALGORITHM_160_H

#include "../util.h"

using namespace std;

namespace leetcode160 {
    class Solution {
    public:
        // 好方法，将两个链表相连
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *p1 = headA;
            ListNode *p2 = headB;
            while (p1 != p2) {
                p1 = (!p1) ? headB : p1->next;
                p2 = (!p2) ? headA : p2->next;
            }
            return p1;
        }


        ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
            ListNode *p1 = headA;
            ListNode *p2 = headB;
            int len1 = 0;
            while (p1) {
                len1++;
                p1 = p1->next;
            }
            int len2 = 0;
            while (p2) {
                len2++;
                p2 = p2->next;
            }
            int diff = abs(len1 - len2);
            p1 = headA;
            p2 = headB;
            if (len1 > len2) {
                while (diff > 0) {
                    p1 = p1->next;
                    diff--;
                }
            }
            else {
                while (diff > 0) {
                    p2 = p2->next;
                    diff--;
                }
            }
            while (p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
                if (!p1 || !p2) {
                    break;
                }
            }
            return p1;
        }
    };
}

#endif //ALGORITHM_160_H