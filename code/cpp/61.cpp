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
    /**
     * 将链表向右旋转 k 步
     * 需要统计出链表的长度
     *
     * @param  {ListNode*} head :
     * @param  {int} k          :
     * @return {ListNode*}      :
     */
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        ListNode* node = head;
        int len = 0;
        while (node) {
            ++len;
            node = node->next;
        }
        k = k % len;
        if (k == 0)
            return head;
        node = head;
        ListNode* pre = head;
        while (k--)
            node = node->next;
        while (node->next) {
            node = node->next;
            pre = pre->next;
        }
        ListNode* newHead = pre->next;
        pre->next = nullptr;
        node->next = head;
        return newHead;
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

    ListNode* head1 = generateList(5);
    printList(head1);

    Solution so;
    ListNode* newHead = so.rotateRight(head1, 8);

    printList(newHead);

    return 0;
}