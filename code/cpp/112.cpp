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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        return dfs(root, targetSum, 0);
    }

    bool dfs(TreeNode* root, const int targetSum, int sum) {
        if (root == nullptr)
            return false;
        sum += root->val;
        if ((sum == targetSum) && root->left == nullptr && root->right == nullptr)
            return true;
        return dfs(root->left, targetSum, sum) || dfs(root->right, targetSum, sum);
    }
};

int main(int argc, char const* argv []) {



    return 0;
}