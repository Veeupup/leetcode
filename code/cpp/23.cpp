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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        ListNode* res = nullptr;
        for (ListNode* list : lists) {
            res = mergeTwoLists(res, list);
        }
        return res;
    }

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, * tail = &head, * aPtr = a, * bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            }
            else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}