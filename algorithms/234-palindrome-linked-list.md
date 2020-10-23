# problem

[234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)

# solution

思路，

找到链表的中间节点，从中间节点开始反转链表，然后从两头开始遍历两个链表对比即可，

时间复杂度 O(N), 空间复杂度 O(1)

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMidNode(head);
        ListNode* last = reverseList(mid);
        while (last != NULL) {
            if (head -> val != last -> val) 
                return false;
            head = head -> next;
            last = last -> next; 
        }
        return true;
    }

    ListNode* findMidNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* nextNode = head;
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

