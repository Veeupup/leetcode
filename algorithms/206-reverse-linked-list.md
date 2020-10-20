# Problem

[206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

# Solution

## 方法一，用栈保存节点

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        stack<ListNode*> sta;
        ListNode* tempNode = head;
        while (tempNode != NULL) {
            sta.push(tempNode);
            tempNode = tempNode -> next;
        }
        ListNode* ans = sta.top();
        sta.pop();
        tempNode = ans;
        while (!sta.empty()) {
            tempNode -> next = sta.top();
            tempNode = sta.top();
            sta.pop();
        }
        tempNode -> next = NULL;
        return ans;
    }
};
```

## 方法二

使用一个 pre 指针保存前一个节点，同时一个临时节点保存当前节点的下一个节点，因为会修改当前节点的指针。

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *nextNode;
        while (head != NULL) {
            nextNode = head -> next;
            head -> next = pre; 
            pre = head;
            head = nextNode;
        }
        return pre;
    }
};
```

