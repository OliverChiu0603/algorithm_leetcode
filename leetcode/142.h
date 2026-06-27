//
// Created by Administrator on 2026/6/27.
//

#ifndef ALGORITHM_142_H
#define ALGORITHM_142_H
#include "../util.h"

namespace leetcode142 {
    class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *fast = head, *slow = head;
            bool foundCycle = false;
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow) {
                    foundCycle = true;
                    break;
                }
            }
            if (!foundCycle) return NULL;

            // 第二阶段：slow 回到 head，两指针同步前进，相遇处即入环点。
            //
            // 易错点：必须「先比较、后移动」。
            // 之前写成「先移动、后比较」是错的：
            //     slow = head;
            //     while (fast) {
            //         fast = fast->next;
            //         slow = slow->next;
            //         if (fast == slow) break;
            //     }
            // 当「入环点恰好是 head」时（头到入环点距离 a == 0），
            // 此时 slow 与 fast 一开始就已相等（都指向 head）。
            // 正确做法应立即返回 head；但先移动会让两者各走一步，
            // 在 head->next 处才 break，导致返回值比真正入环点偏后一位。
            // a > 0 时碰巧不受影响，所以这个 bug 平时不易暴露。
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    };
}

#endif //ALGORITHM_142_H