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
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        stack<TreeNode*> sta;
        TreeNode* node = root;
        int pre;
        bool firstNode = true;
        while (!sta.empty() || node != nullptr) {
            while (node) {
                sta.push(node);
                node = node->left;
            }
            if (node == nullptr) {
                node = sta.top();
                sta.pop();
                if (firstNode) {
                    firstNode = false;
                }
                else if (node->val <= pre)
                    return false;
                pre = node->val;
                node = node->right;
            }
        }
        return true;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}