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
        if (head == nullptr)
            return head;
        ListNode* dumbNode = new ListNode(INT_MIN);
        ListNode* node = dumbNode;
        ListNode* pre = dumbNode;
        while (head != nullptr) {
            if (node->val != head->val) {
                node->next = head;
                pre = node;
                node = node->next;
                head = head->next;
            }
            else {
                pre->next = nullptr;
                while (head != nullptr && node->val == head->val) {    // 遇到相同的节点，那么遍历完之后所有相同的节点
                    head = head->next;
                }
                node = pre;
            }
        }
        return dumbNode->next;
    }
};

int main(int argc, char const* argv []) {

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2); 
    ListNode* node31 = new ListNode(3);
    ListNode* node32 = new ListNode(3);
    ListNode* node33 = new ListNode(3);
    ListNode* node41 = new ListNode(4);
    ListNode* node42 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
        
    node1->next = node2;
    node2->next = node31;
    node31->next = node32;
    node32->next = node33;
    node33->next = node41;
    node41->next = node42;
    node42->next = node5;
    
    Solution so;
    ListNode* res = so.deleteDuplicates(node1);
        
    while (res) {
        cout << res->val << "->";
        res = res->next;
    }
    cout << endl;
        
    return 0;
}
