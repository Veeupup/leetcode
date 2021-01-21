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
     * 计算一颗二叉搜索树是否是平衡二叉搜索树，任意节点的左右子树深度相差不超过1，就是平衡二叉搜索树
     * 对于每个节点递归操作
     * @param  {TreeNode*} root : 
     * @return {bool}           : 
     */
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        queue<TreeNode*> iq;
        iq.push(root);
        TreeNode* tmp;
        while (!iq.empty())
        {
            tmp = iq.front();
            if (abs(maxDepth(tmp->left) - maxDepth(tmp->right)) > 1) {
                return false;
            }
            iq.pop();
            if (tmp->left != NULL)
                iq.push(tmp->left);
            if (tmp->right != NULL)
                iq.push(tmp->right);
        }
        return true;
    }

    bool isBalanced2(TreeNode* root) {
        if (!root)
            return true;
        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced2(root->left) && isBalanced2(root->right);
    }
    
private:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{ 

    

    
    return 0;
}