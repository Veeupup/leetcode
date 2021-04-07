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
    vector<int> nums;
    void preorder(TreeNode* root) {
        if (!root)
            return;
        preorder(root->left);
        nums.push_back(root->val);
        preorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        preorder(root);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}