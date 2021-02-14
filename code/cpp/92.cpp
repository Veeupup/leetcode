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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;
        ListNode* dumbNode = new ListNode(-1, head);
        ListNode* left = dumbNode;
        while (m > 1) {
            left = left->next;
            m--;
        }
        ListNode* right = dumbNode;
        while (n) {
            right = right->next;
            n--;
        }
        left->next = reverseLists(left->next, right);
        return dumbNode->next;
    }

    ListNode* reverseLists(ListNode* begin, ListNode* end) {
        // 2->3->4
        // l = 2, r = 4, pre = null
        // 1: next=3, 2->nullptr, pre=2, l=3
        // 2: next=4, 3->2->nullptr, pre=3, l=4
        // 4->3->2->nullptr
        ListNode* l = begin;
        ListNode* r = end;
        ListNode* pre = end->next;
        while (l != r) {
            ListNode* nextTmp = l->next;
            l->next = pre;
            pre = l;
            l = nextTmp;
        }
        l->next = pre;
        return end;
    }
};

ListNode* generateList(int n) {
    ListNode* head = new ListNode(1);
    ListNode* node = head;
    for (int i = 2; i <= n; i++) {
        node->next = new ListNode(i);
        node = node->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* node = head;
    while (node) {
        cout << node->val << ", ";
        node = node->next;
    }
    cout << endl;
}

int main(int argc, char const* argv []) {

    ListNode* head = generateList(5);
    printList(head);

    Solution so;
    head = so.reverseBetween(head, 2, 4);

    printList(head);

    return 0;
}