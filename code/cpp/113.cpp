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
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        backtrace(root, targetSum, 0);
        return res;
    }

    void backtrace(TreeNode* root, int targetSum, int sum) {
        if (root == nullptr)
            return;
        sum -= root->val;
        path.push_back(root->val);
        if (sum == targetSum && root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
        }
        backtrace(root->left, targetSum, sum);
        backtrace(root->right, targetSum, sum);
        path.pop_back();
    }
};

int main(int argc, char const* argv []) {




    return 0;
}