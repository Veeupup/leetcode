#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */

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
    // 层序遍历，从第一个不是 nullptr 到最后一个数字之间的长度
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        TreeNode* node = root;
        queue<TreeNode*> qu;
        qu.push(root);
        root->val = 0;
        int max_len = 1;
        while (!qu.empty()) {
            max_len = max(max_len, qu.back()->val - qu.front()->val + 1);

            int offset = qu.front()->val;
            int n = qu.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = qu.front();
                qu.pop();
                node->val -= offset;

                if (node->left) {
                    node->left->val = 2 * node->val;
                    qu.push(node->left);
                }

                if (node->right) {
                    node->right->val = 2 * node->val + 1;
                    qu.push(node->right);
                }
            }
        }
        return max_len;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}