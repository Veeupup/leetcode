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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}