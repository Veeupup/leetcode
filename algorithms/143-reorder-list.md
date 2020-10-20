[TOC]

# Problem

[143. 重排链表](https://leetcode-cn.com/problems/reorder-list/)

# Solution



## 方法一，链表保存到vector中

将链表保存到数组中即可以随机寻址，然后可以自由调换位置

1，链表保存到 vector 中

```c++
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr)
            return;
        ListNode* tempNode = head;
        vector<ListNode*> nodes;
        while(tempNode != nullptr) {
            nodes.emplace_back(tempNode);
            tempNode = tempNode -> next;
        }
        int i = 0, j = nodes.size() - 1;
        bool flag = true;
        while (i < j) {
            nodes[i] -> next = nodes[j];
            i++;
            if (i == j) 
                break;
            nodes[j] -> next = nodes[i];
            j--;
        }
        nodes[i] -> next = nullptr;
    }
};
```



## 方法二，寻找链表中点 + 链表逆序 + 合并链表

注意到目标链表即为将原链表的左半端和反转后的右半端合并后的结果。

这样我们的任务即可划分为三步：

* 找到原链表的中点（参考「[876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/)」）。

我们可以使用快慢指针来 O(N) 地找到链表的中间节点。

* 将原链表的右半端反转（参考「[206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)」）。

我们可以使用迭代法实现链表的反转。

* 将原链表的两端合并。

因为两链表长度相差不超过 1，因此直接合并即可。

```c++
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr)
            return;
        ListNode* mid = findMid(head);
        ListNode* l1 = head;
        ListNode* l2 = mid -> next;
        mid -> next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr,* nextNode;
        while (head != nullptr) {
            nextNode = head -> next;
            head -> next = pre;
            pre = head;
            head = nextNode;
        }
        return pre;
    }

    ListNode* findMid(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }   

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1 -> next;
            l2_tmp = l2 -> next;

            l1 -> next = l2;
            l1 = l1_tmp;

            l2 -> next = l1;
            l2 = l2_tmp;
        }
    }
};
```

