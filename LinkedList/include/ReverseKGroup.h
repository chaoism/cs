/**
 * @file ReverseKGroup.h
 * @author chaoism
 * @brief K 个一组翻转链表
 * @version 0.1
 * @date 2022-06-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "ListNode.h"

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *rev = nullptr;
        ListNode *cur = head;

        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = rev;
            rev = cur;
            cur = next;
        }

        return rev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // int i = 0, j = 0;
        if (k == 1)
            return head;

        ListNode *rev = new ListNode(-1);
        ListNode *tmp = rev;

        while (head)
        {
            ListNode *l1 = head;
            // int i = 1;
            // while (i <= k && l1)
            // {
            //     i++;
            //     l1 = l1->next;
            // }
            for (size_t i = 0; i < k; i++)
            {
                l1 = l1->next;
            }

            if (i == k)
            {
                ListNode *next = l1->next;
                l1->next = nullptr;
                tmp->next = reverse(head);
                head = next;
                tmp = tmp->next;
            }
            if (i < k)
            {
                tmp->next = head;
            }
        }

        return rev;
    }
};