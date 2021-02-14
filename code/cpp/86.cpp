#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // 2. 模拟法
        ListNode* smallHead = new ListNode(0);
        ListNode* bigHead = new ListNode(0);
        ListNode* smallNode = smallHead;
        ListNode* bigNode = bigHead;
        while (head != nullptr) {
            if (head->val < x) {
                smallNode->next = head;
                smallNode = smallNode->next;
            }
            else {
                bigNode->next = head;
                bigNode = bigNode->next;
            }
            head = head->next;
        }
        bigNode->next = nullptr;
        smallNode->next = bigHead->next;
        return smallHead->next;
        // 1. 暴力法，使用两个数组保存应该分隔开的节点
        // if (head == nullptr || head->next == nullptr)
        //     return head;
        // vector<ListNode*> smallNodes, bigNodes;
        // while (head) {
        //     if (head->val < x)
        //         smallNodes.push_back(head);
        //     else
        //         bigNodes.push_back(head);
        //     head = head->next;
        // }
        // ListNode* dumbNode = new ListNode(-1);
        // head = dumbNode;
        // for (auto node : smallNodes) {
        //     head->next = node;
        //     head = head->next;
        // }
        // for (auto node : bigNodes) {
        //     head->next = node;
        //     head = head->next;
        // }
        // head->next = nullptr;
        // head = dumbNode->next;
        // delete dumbNode;
        // return head;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}