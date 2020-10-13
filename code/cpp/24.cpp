#include <bits/stdc++.h> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* swapNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr)  
            return head;
        ListNode* temNode = swapNode(head->next->next);
        ListNode* node2 = head->next;
        head->next = temNode;
        node2->next = head;
        return node2;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = swapNode(head);
        return ans;
    }
};

int main() {
    Solution *so = new Solution();
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    ListNode* ans = so->swapPairs(head);
    while (head != nullptr)
    {
        cout << head->val << " ";
    }
    cout << endl;
    
    return 0;
}
