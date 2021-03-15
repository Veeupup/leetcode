#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        if (abs(getDepth(root->left) - getDepth(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;
        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced2(TreeNode* root) {
        return height(root) >= 0;
    }

    int getDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
};

int main(int argc, char const* argv []) {




    return 0;
}