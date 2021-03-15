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
    /**
     * 根据前序遍历和中序遍历重建二叉树
     * 前序遍历可以找到每个子树的根节点 中序遍历可以找到左右子树
     * @param  {vector<int>} preorder :
     * @param  {vector<int>} inorder  :
     * @return {TreeNode*}            :
     */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildBinTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildBinTree(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end) {
        if (pre_start > pre_end)
            return nullptr;
        int val = preorder[pre_start];
        TreeNode* root = new TreeNode(val);
        int pos;
        for (int i = in_start; i <= in_end; i++) {
            if (inorder[i] == val) {
                pos = i;
                break;
            }
        }
        int left_len = pos - in_start;
        root->left = buildBinTree(preorder, pre_start + 1, pre_start + left_len,
            inorder, in_start, pos - 1);
        root->right = buildBinTree(preorder, pre_start + left_len + 1, pre_end,
            inorder, pos + 1, in_end);
        return root;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}