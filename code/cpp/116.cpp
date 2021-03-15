#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        Node* leftmost = root;
        while (leftmost->left != nullptr) {
            Node* head = leftmost;
            while (head) {
                // connection 1
                head->left->next = head->right;
                // connection 2
                if (head->next) {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            leftmost = leftmost->left;
        }
        return root;

        
        // if (root == nullptr)
        //     return root;
        // queue<Node*> que;
        // que.push(root);
        // while (!que.empty()) {
        //     int n = que.size();
        //     for (int i = 0; i < n - 1; i++) {
        //         auto cur = que.front();
        //         que.pop();
        //         cur->next = que.front();
        //         if (cur->left)
        //             que.push(cur->left);
        //         if (cur->right)
        //             que.push(cur->right);
        //     }
        //     auto cur = que.front();
        //     que.pop();
        //     cur->next = nullptr;
        //     if (cur->left)
        //         que.push(cur->left);
        //     if (cur->right)
        //         que.push(cur->right);
        // }
        // return root;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}