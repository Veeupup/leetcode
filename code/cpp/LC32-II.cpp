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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode*> iq;
        iq.push(root);
        TreeNode* cur;
        while (!iq.empty()) {
            vector<int> tmp;
            int cnt = iq.size();
            while (cnt-- > 0) {
                cur = iq.front();
                iq.pop();
                tmp.emplace_back(cur->val);
                if (cur->left) iq.push(cur->left);
                if (cur->right) iq.push(cur->right);
            }
            if (res.size() & 1) {
                reverse(tmp.begin(), tmp.end());
                res.emplace_back(tmp);
            }else {
                res.emplace_back(tmp);
            }
        }
        return res;
    }
};

int main() {



    return 0;
}