#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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

    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right != nullptr)
            return 1 + minDepth(root->right);
        if (root->left != nullptr && root->right == nullptr)
            return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<pair<TreeNode*, int>> que;
        que.emplace(root, 1);
        while (!que.empty()) {
            TreeNode* node = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }
            if (node->left != nullptr) {
                que.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr) {
                que.emplace(node->right, depth + 1);
            }
        }

        return 0;
    }

    // int minDepth(TreeNode* root) {
    //     if (root == nullptr)
    //         return 0;
    //     queue<TreeNode*> _q;
    //     _q.push(root);
    //     int depth = 1;
    //     while (!_q.empty()) {
    //         int sz = _q.size();
    //         for (int i = 0; i < sz; ++i) {
    //             TreeNode* top = _q.front();
    //             _q.pop();
    //             if (top->left == nullptr && top->right == nullptr)
    //                 return depth;
    //             if (top->left != nullptr)
    //                 _q.push(top->left);
    //             if (top->right != nullptr)
    //                 _q.push(top->right);
    //         }
    //         ++depth;
    //     }
    //     return depth;
    // }
};

int main(int argc, char const* argv []) {




    return 0;
}