#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * 层次遍历，每层单独输出
 * 每层的元素节点个数其实是已知的，包含 NULL 节点
 * 然后将 root 也加入到 queue 中去，然后每次读取一个值，然后增加计数
 * 
 */


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
            for (int i = iq.size(); i > 0; i--) {
                cur = iq.front();
                iq.pop();
                tmp.emplace_back(cur->val);
                if (cur->left)
                    iq.push(cur->left);
                if (cur->right)
                    iq.push(cur->right);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};

int main() {



    return 0;
}