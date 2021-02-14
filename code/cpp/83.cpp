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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            else {
                cur = cur->next;
            }
        }
        return head;
        // if (head == nullptr)
        //     return head;
        // ListNode* dumbNode = new ListNode(INT_MIN);
        // ListNode* node = dumbNode;
        // while (head != nullptr) {
        //     if (node->val != head->val) {
        //         node->next = head;
        //         node = node->next;
        //     }
        //     head = head->next;
        // }
        // node->next = nullptr;
        // head = dumbNode->next;
        // delete dumbNode;
        // return head;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}