#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> iv;
        inorder(root, iv);
        return *(iv.end() - k);
    }
private:
    void inorder(TreeNode* root, vector<int>& iv) {
        if (root == NULL)
            return;
        inorder(root->left, iv);
        iv.emplace_back(root->val);
        inorder(root->right, iv);
    }
};

int main() {




    return 0;
}