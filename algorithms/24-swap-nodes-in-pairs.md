[TOC]

# Problem

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


 ```
示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
 ```




# Solution

## 分析和思路

使用递归函数来进行节点的交换，每次递归函数的返回值就是当前两个节点交换之后首节点的指针，这样将一个两两交换的为题变成了多个相同的问题。

大佬太强了，自己想不到这样的解法。



执行结果：

通过

显示详情

执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗：7.5 MB, 在所有 C++ 提交中击败了5.30%的用户

## code

```c++
class Solution {
private:
    ListNode* swapNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr)  
            return head;
        ListNode* temNode = swapNode(head->next->next);
        ListNode* node2 = head->next;
        head->next = temNode;
        node2->next = head;
        return node2;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = swapNode(head);
        return ans;
    }
};
```

