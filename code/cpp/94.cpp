#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        TreeNode* node = root;
        while (!sta.empty() || node != nullptr) {
            while (node != nullptr) {
                sta.push(node);
                node = node->left;
            }
            
            if (node == nullptr) {
                node = sta.top();
                sta.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}