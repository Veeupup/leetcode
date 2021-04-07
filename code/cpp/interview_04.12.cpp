#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 路径和
    // 应该记录下到每个点的路径和
    // 遍历到更深的地方时，用当前的和来和之前的和进行做差
    int cnt = 0;
    int target;
    vector<int> parentSum {0};
    int pathSum(TreeNode* root, int sum) {
        target = sum;
        findSum(root);
        return cnt;
    }

    void findSum(TreeNode* root) {
        if (!root)
            return;
        int sum = parentSum.back() + root->val;
        for (const int& parent : parentSum) {
            if (sum - parent == target)
                ++cnt;
        }
        parentSum.push_back(sum);
        findSum(root->left);
        findSum(root->right);
        parentSum.pop_back();
    }
    
};

int main(int argc, char const* argv []) {




    return 0;
}