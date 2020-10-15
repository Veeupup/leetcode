#include <bits/stdc++.h> 
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;

        queue<Node*> Q;
        Q.push(root);

        while (!Q.empty())
        {
            int size = Q.size();
            for (int i = 0; i < size; i++)
            {
                Node* node = Q.front();
                Q.pop();

                if (i < size - 1)
                    node->next = Q.front();

                if (node->left != nullptr)
                    Q.push(node->left);
                if (node->right != nullptr)
                    Q.push(node->right);
            }
        }
    
        return root;
    }
    Node* connect2(Node* root) {
        if (root == nullptr)
            return root;
        Node* leftmost = root;
        while (leftmost->left != nullptr)
        {
            Node* head = leftmost;

            while (head != nullptr)
            {
                head->left->next = head->right;

                if (head->next != nullptr) 
                    head->right->next = head->next->left;
                
                head = head->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};

int main() {
    Solution *so = new Solution();
    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    queue<Node*> sta;
    sta.push(root);
    Node* tempNode;
    while (!sta.empty())
    {
        tempNode = sta.front();
        if (tempNode->left != nullptr)
            sta.push(tempNode->left);
        if (tempNode->right != nullptr)
            sta.push(tempNode->right);
        sta.pop();  // 顶部的 node 离开当前层
        cout << tempNode->val << " ";
    }
    

    return 0;
}
