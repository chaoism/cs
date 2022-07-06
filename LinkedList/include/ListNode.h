/**
 * @file ListNode.h
 * @author chaoism
 * @brief Leetcode ListNode 头文件 辅助函数
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void print(ListNode *head)
    {
        cout << "[ ";
        while (head)
        {
            std::cout << head->val;
            if ((head = head->next))
            {
                std::cout << " -> ";
            }
        }
        std::cout << " ]" << std::endl;
    }

    ListNode *vec2ListNode(vector<int> &vec)
    {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;

        for (auto &&i : v)
        {
            cur->next = new ListNode(i);
            cur = cur->next;
        }

        return head;
    }
};
