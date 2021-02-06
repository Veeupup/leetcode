#include <bits/stdc++.h>
using namespace std;

/**
* 二叉树的非递归遍历
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void handle_node(TreeNode* node) {
    cout << node->val << " ->";
}

void pre_order(TreeNode* root) {
    stack<TreeNode*> sta;
    TreeNode* node = root;
    sta.push(node);
    while (!sta.empty()) {
        node = sta.top();
        sta.pop();
        handle_node(node);
        if (node->right)
            sta.push(node->right);
        if (node->left)
            sta.push(node->left);
    }
    cout << endl;
}

void in_order(TreeNode* root) {
    stack<TreeNode*> sta;
    TreeNode* node = root;
    while (!sta.empty() || node != NULL) {
        while (node != NULL) {
            sta.push(node);
            node = node->left;
        }
        node = sta.top();
        sta.pop();
        handle_node(node);
        node = node->right;
    }
    cout << endl;
}

void post_order(TreeNode* root) {
    stack<TreeNode*> sta1, sta2;
    TreeNode* node = root;
    sta1.push(node);
    while (!sta1.empty()) {
        node = sta1.top();
        sta1.pop();
        sta2.push(node);
        if (node->left)
            sta1.push(node->left);
        if (node->right)
            sta1.push(node->right);
    }
    while (!sta2.empty()) {
        node = sta2.top();
        sta2.pop();
        handle_node(node);
    }
    cout << endl;
}


int main(int argc, char const* argv []) {

    /**
    *             0
    *       1           2
    *     3   4      5     8
    *   6       7
    */

    TreeNode* root = new TreeNode(0);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);

    root->left = node1;
    root->right = node2;

    node1->left = node3;
    node1->right = node4;

    node3->left = node6;
    node4->right = node7;

    node2->left = node5;
    node2->right = node8;

    pre_order(root);
    in_order(root);
    post_order(root);

    return 0;
}