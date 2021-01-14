#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/**
*   拷贝链表中的指向关系
*/

class Solution {
public:
    // 使用 map 保存原来的指向关系，然后新建
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        unordered_map<Node*, Node*> imap;// 建立新旧节点的映射关系
        Node* cur = head;
        while (cur) {
            imap[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur)
        {
            imap[cur]->next = imap[cur->next];
            imap[cur]->random = imap[cur->random];
            cur = cur->next;
        }
        return imap[head];
    }

    // 先构造一条新的放在原来的后面，然后将两个链表分隔开
    Node* copyRandomList2(Node* head) {
        Node* cur = head;
        // 1. 复制 next
        while (cur) 
        {
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        // 2. 复制 random 指向
        cur = head;
        while (cur)
        {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        // 3. 分割链表
        
        cur = head->next;
        Node* pre = head, *res = head->next;
        while (cur->next) {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        return res;
    }
};

int main()
{ 

    

    return 0;
}