#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        ListNode* dumbNode = new ListNode(-1, head);
        ListNode* pre = dumbNode;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p1 && p2) {
            pre->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            pre = p1;
            p1 = p1->next;
            if (!p1 || !p1->next)
                break;
            p2 = p1->next->next;
        }
        return dumbNode->next;
    }

    ListNode* swapPairs2(ListNode* head) {
        ListNode* dumbNode = new ListNode(-1, head);
        ListNode* tempNode = dumbNode;
        while (tempNode->next && tempNode->next->next) {
            ListNode* node1 = tempNode->next;
            ListNode* node2 = tempNode->next->next;
            tempNode->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            tempNode = node1;
        }
        return dumbNode->next;
    }

    ListNode* swapPairs3(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* newHead = head->next;
        head->next = swapPairs3(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}