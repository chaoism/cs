#include "ListNode.h"
#include <vector>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *rev = nullptr;
        while(head)
        {
            ListNode *tmp = head->next;
            head->next = rev;
            rev = head;
            head = tmp;
        }

        return rev;
    }
};