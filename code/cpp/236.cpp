#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool dfs2(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (root == p) {
            path.push_back(root);
            return true;
        }else {
            path.push_back(root);
            if (root->left && dfs(root->left, p, path))
                return true;
            if (root->right && dfs(root->right, p, path))
                return true;
            path.pop_back();
            return false;
        }
    }

    TreeNode* ancestor;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ancestor = root;
        }
        return lson || rson || (root->val == p->val || root->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ancestor;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}