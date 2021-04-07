#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* nex = head->next;
            head->next = pre;
            pre = head;
            head = nex;
        }
        return pre;
    }

    // 找到中点，然后链表翻转，然后依次加入
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* head2 = reverse(slow);
        ListNode* dumb = new ListNode(-1);
        ListNode* node = dumb;
        bool flag = true;
        while (head2 && head) {
            if (flag) {
                node->next = head;
                head = head->next;
            }
            else {
                node->next = head2;
                head2 = head2->next;
            }
            flag = !flag;
            node = node->next;
        }
        head = dumb->next;
        delete dumb;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}