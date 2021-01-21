#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    /**
     * 找到链表的第一个公共节点
     * 遍历 A，存入 set，然后遍历 B，获得第一个元素
     * @param  {ListNode*} headA :
     * @param  {ListNode*} headB :
     * @return {ListNode*}       :
     */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        while (node1 != node2)         {
            node1 = node1 != NULL ? node1->next : headB;
            node2 = node2 != NULL ? node2->next : headA;
        }
        return node1;
        // unordered_set<ListNode*> iset;
        // ListNode* tempA = headA;
        // ListNode* tempB = headB;
        // while (tempA != NULL) {
        //     iset.insert(tempA);
        //     tempA = tempA->next;
        // }
        // while (tempB != NULL) {
        //     if (iset.find(tempB) != iset.end())
        //         return tempB;
        //     tempB = tempB->next;
        // }
        // return NULL;
    }
};

int main() {




    return 0;
}