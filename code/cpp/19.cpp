#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dumbNode = new ListNode();
        dumbNode->next = head;

        ListNode* front = head;
        ListNode* back = dumbNode;

        while (n) {
            front = front->next;
            n--;
        }

        while (front != nullptr) {
            front = front->next;
            back = back->next;
        }

        back->next = back->next->next;
        ListNode* res = dumbNode->next;
        // delete dumbNode;
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}