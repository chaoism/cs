# Linked List 链表

特点：

- 存储内存是不连续的
- 不支持随机读取，查找的时间复杂度 *`O(n)`*
- 链表在插入数据的时候可以达到 *`O(1)`* 的复杂度

分类：

- 单向链表
- 双向链表
- 循环链表

## 基本操作

1. 链表的构造，由数组等元素成员构造一个链表

```c++
// 构造 head和tail 指针，指向链表的头和尾
ListNode *head = nullptr, *tail = nullptr;

for (size_t i = 0; i < vec.size(); i++)
{
    if (!head) // 链表为空时，head = tail
    {
        head = tail = new ListNode(vec[i]);
    }
    else
    {
        // 尾指针移动
        tail->next = new ListNode(vec[i]);
        tail = tail->next;
    }
}
```

```c++
ListNode *head = new ListNode(0);
ListNode *tmp = head;

for (auto &&i : vec)
{
    tmp->next = new ListNode(i);
    tmp = tmp->next;
}

// 返回 head->next 即是要构造的链表
```

- [两数之和](include/AddTwoNumbers.h)

- [合并两个有序的链表](include/MergeTwoLists.h)

2. 链表的反转

```c++
ListNode* reverseList(ListNode* head) {
    ListNode *rev = nullptr;
    ListNode *cur = head;

    while(cur)
    {
        // 首先断链，保存当前节点的next部分
        ListNode *tmp = cur->next;

        // rev存的是已反转的部分，第一个节点时，next为定义的nullptr
        cur->next = rev;

        // 更新已反转的部分
        rev = cur;

        // 当前节点移动
        cur = tmp;
    }

    return rev;
}
```

- [链表反转Ⅰ](include/ReverseList.h)

- [链表反转Ⅱ]

3. 链表的插入

4. 链表的删除
