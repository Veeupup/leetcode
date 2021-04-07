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
    // 另外一种方法，分别两条链比较大小
    ListNode* partition(ListNode* head, int x) {
        ListNode* root = head;
        ListNode* bigIdx = head;
        while (head) {
            if (head->val < x) {
                swap(head->val, bigIdx->val);
                bigIdx = bigIdx->next;
            }
            head = head->next;
        }
        return root;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}