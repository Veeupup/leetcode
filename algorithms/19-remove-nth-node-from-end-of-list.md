[TOC]

# Problem

[19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

# Solution

## 分析和思路

1，自己思路

使用双指针来计数，因为要删除倒数第 k 个节点，所以有一个慢指针比快指针走得慢，快慢指针之间的距离应该就是 k，因为当快指针到达末尾的时候，慢指针应该指向被删除节点的前一个节点。当删除的节点是第一个节点的时候，直接返回首节点的下一个节点即可。

2，添加**哑节点（dummy node）**

在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 \textit{next}next 指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。

例如，在本题中，如果我们要删除节点 y，我们需要知道节点 y 的前驱节点 x，并将 x 的指针指向 y 的后继节点。但由于头节点不存在前驱节点，因此我们需要在删除头节点时进行特殊判断。但如果我们添加了哑节点，那么头节点的前驱节点就是哑节点本身，此时我们就只需要考虑通用的情况即可。

当添加哑节点之后，让first 指针正常走，second 指针指向 dummy node 即可，此时 dummy node 指向的就是要删除节点的前一个节点。



## code

1. 自己code

```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return head;
        ListNode* ans = head;
        int lastPos = 0;
        ListNode* lastNode = head;
        ListNode* deleteNode = head;
        while (lastNode != nullptr) {
            if (lastPos > n) {
                deleteNode = deleteNode -> next;
            }
            lastNode = lastNode -> next;
            lastPos++;
        }
        if (lastPos == n)
            return head -> next;
        if (deleteNode -> next != nullptr)
            deleteNode -> next = deleteNode -> next -> next;
        else 
            deleteNode -> next = nullptr;
        return head;
    }
};
```

2. 添加哑节点

```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for(int i = 0; i < n; ++i) {
            first = first -> next;
        }
        while (first != nullptr) {
            first = first -> next;
            second = second -> next;
        }
        second -> next = second -> next -> next;
        ListNode* ans = dummy -> next;
        delete dummy;
        return ans;
    }
};
```

3. 递归

```c++
class Solution {
public:
    int cnt = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return head;
        head->next = removeNthFromEnd(head->next, n);
        cnt++;
        if (cnt == n)
            return head->next;
        return head;
    }
};
```

