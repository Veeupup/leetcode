/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        // 左子树为空,不比较,只看右子树
        if(root->left == NULL && root->right != NULL) {
            return 1 + minDepth(root->right);
        }
        // 右子树为空,不比较,只看左子树
        if(root->right == NULL && root->left != NULL) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};