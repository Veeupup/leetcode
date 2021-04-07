#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr)
            return head;
        unordered_set<int> vals = { head->val };
        ListNode* pre = head;
        while (pre->next) {
            ListNode* cur = pre->next;
            if (!vals.count(cur->val)) {    // 不存在
                vals.insert(cur->val);
                pre = pre->next;
            }
            else {
                pre->next = pre->next->next;
            }
        }
        pre->next = nullptr;
        return head;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}