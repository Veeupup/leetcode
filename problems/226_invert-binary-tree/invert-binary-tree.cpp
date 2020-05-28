/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        TreeNode *rootLeft = root->left == NULL ? NULL : root->left;
        TreeNode *rootRight = root->right == NULL ? NULL : root->right;
        root->left = rootRight;
        root->right = rootLeft;
        if (root->left != NULL)
            invertTree(root->left);
        if (root->right != NULL)
            invertTree(root->right);
        return root;
    }
};