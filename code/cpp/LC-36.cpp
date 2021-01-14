#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.

    将二叉搜索树转变成循环双向链表
    先序遍历找到最左的

    二叉搜索树的中序遍历是有序的

*/

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* pre = NULL;
    Node* head = NULL;
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return NULL;
        inorder(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void inorder(Node* cur) {
        if (!cur)
            return;
        inorder(cur->left);
        if (pre)
            pre->right = cur;
        else
            head = cur; // 保存第一个节点，没有前置节点
        cur->left = pre;
        pre = cur;
        inorder(cur->right);
    }
};

int main() {



    return 0;
}