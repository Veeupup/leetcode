#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
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


class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes;
        Node* cur = head;
        while (cur) {
            nodes[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            nodes[cur]->next = nodes[cur->next];
            nodes[cur]->random = nodes[cur->random];
            cur = cur->next;
        }
        return nodes[head];
    }
};

int main(int argc, char const* argv []) {




    return 0;
}