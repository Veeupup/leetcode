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
    unordered_map<int, int> index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0, size = inorder.size(); i < size; i++) {
            index[inorder[i]] = i;
        }
        return buildMyTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* buildMyTree(vector<int>& inorder, int in_start, int in_end,
        vector<int>& postorder, int post_start, int post_end) {
        if (in_start > in_end)
            return nullptr;
        int val = postorder[post_end];
        TreeNode* root = new TreeNode(val);
        int root_pos = index[val];
        int leftLen = root_pos - in_start;
        root->left = buildMyTree(inorder, in_start, root_pos - 1,
            postorder, post_start, post_start + leftLen - 1);
        root->right = buildMyTree(inorder, root_pos + 1, in_end,
            postorder, post_start + leftLen, post_end - 1);
        return root;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}