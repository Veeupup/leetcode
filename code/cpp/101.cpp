#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSym(root->left, root->right);
    }
    
    bool isSym(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == NULL && rightNode == NULL)
            return true;
        if ((leftNode == NULL && rightNode != NULL) || (leftNode != NULL && rightNode == NULL))
            return false;
        if (leftNode->val != rightNode->val)
            return false;
        return isSym(leftNode->left, rightNode->right) && isSym(leftNode->right, rightNode->left);
    }
};

int main(int argc, char const* argv []) {




    return 0;
}