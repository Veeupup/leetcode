#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 找到中间节点，如果是奇数个节点，那么刚好是中间的节点
        // 如果是偶数个节点，那么就是之前的那个节点
        // 所以说 p1 可能比较短
        ListNode* p1 = head;
        ListNode* tmp = reverse(slow);
        ListNode* p2 = tmp;

        
        // 
        bool result = true;
        while (result && p1) {
            if (p1->val != p2->val)
                result = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        slow = reverse(tmp);
        return result;
    }

    ListNode* reverse(ListNode* root) {
        ListNode* head = root;
        ListNode* pre = NULL;
        while (head) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};

int main(int argc, char const* argv []) {

    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(2);
    ListNode *n4 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
        
    Solution so;
    cout << so.isPalindrome(n1) << endl;

    while (n1) {
        cout << n1->val << ", ";       
        n1 = n1->next;
    }
        
    return 0;
}