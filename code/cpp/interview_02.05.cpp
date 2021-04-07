#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int flag = 0;
        while (l1 || l2) {
            int x1 = l1 ? l1->val : 0;
            int x2 = l2 ? l2->val : 0;
            int sum = x1 + x2 + flag;
            if (sum >= 10)
                flag = 1;
            else
                flag = 0;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (flag)
            cur->next = new ListNode(flag);
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }

};

int main(int argc, char const* argv []) {




    return 0;
}