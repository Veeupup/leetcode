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
    // LCA, 判断两个节点是否在同一颗子树中
    TreeNode* ancestor = nullptr;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root == p || root == q) && (lson || rson)))
            ancestor = root;
        return lson || rson || ((root == p) || (root == q));
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ancestor;
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}