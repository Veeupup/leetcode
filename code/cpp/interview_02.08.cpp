#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next)
            return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        int t = 0;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            ++t;
            if (fast == slow)
                break;
        }
        if (!fast || !fast->next)
            return NULL;
        fast = head;
        slow = head;
        while (t-- > 0) {
            fast = fast->next;
        }
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}