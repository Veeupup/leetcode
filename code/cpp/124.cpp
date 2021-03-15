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
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftVal = max(dfs(root->left), 0);
        int rightVal = max(dfs(root->right), 0);

        int priceNewPath = root->val + leftVal + rightVal;

        max_sum = max(max_sum, priceNewPath);

        return max(leftVal, rightVal) + root->val;
    }

};

int main(int argc, char const* argv []) {




    return 0;
}