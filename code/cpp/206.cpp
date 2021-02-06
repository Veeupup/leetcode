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
     * 反转链表
     *
     * 1->2->3
     * 反转
     * temp = cur->next
     * cur->next = pre
     * pre = cur
     * cur = temp
     *
     *
     * @param  {ListNode*} head :
     * @return {ListNode*}      :
     */
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}