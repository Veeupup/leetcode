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
    /**
     * 二叉树，不能打劫相邻的节点
     *
     * 对于每个节点，有两种可能，打劫，或者不打劫，如果打劫，就不能打劫子节点，不打劫，就可以打劫子节点
     * rob(root): max { root->val + rob(root->left->left, root->left->right) };
     *
     * 终结情况：如果 root == NULL, return 0
     *
     * @param  {TreeNode*} root :
     * @return {int}            :
     */
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (memo.count(root))
            return memo[root];
        int do_it = root->val +
            (root->left == NULL ? 0 : rob(root->left->left) + rob(root->left->right)) +
            (root->right == NULL ? 0 : rob(root->right->left) + rob(root->right->right));

        int not_do_it = rob(root->left) + rob(root->right);
        int res = max(do_it, not_do_it);
        memo[root] = res;
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}