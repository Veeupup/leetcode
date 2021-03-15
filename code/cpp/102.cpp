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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> iq;
        iq.push(root);
        TreeNode* node;
        while (!iq.empty()) {
            int len = iq.size();
            vector<int> nowLevel(len);
            for (int i = 0; i < len; i++) {
                node = iq.front();
                iq.pop();
                nowLevel[i] = node->val;
                if (node->left)
                    iq.push(node->left);
                if (node->right)
                    iq.push(node->right);
            }
            res.emplace_back(nowLevel);
        }
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}