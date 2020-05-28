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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *nextNode;
        while(head != NULL)
        {
            nextNode = head->next;  // 先保存下一个结点
            head->next = pre;       // 当该当前结点的下一个为上一个
            pre = head;             
            head = nextNode;
        }
        return pre;
    }
};