#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * 自己的思路：
     *  生成二叉搜索树，给定一个序列就可以生成一个搜索二叉树
     * 这个题考的就是生成 1～n 的不同序列，每个序列生成一个搜索二叉树
     *  但是有个问题，那就是在生成搜索二叉树的时候，有可能生成重复的搜索二叉树
     *  需要去重，两个地方可以去重，
     *      一个是在生成序列的时候就去重，另外一个是在生成二叉树之后再去重
     *
     * 这个思路是不好的，因为去重不好做，所以不能这么做
     *
     * 递归的思路
     *
     * @param  {int} n              : 1～n 个节点
     * @return {vector<TreeNode>*}  : 搜索二叉树的根节点
     */
    vector<TreeNode*> generateTrees(int n) {
        if (!n)
            return {};
        return generateAns(1, n);
    }

    vector<TreeNode*> generateAns(int start, int end) {
        if (start > end)
            return { nullptr };
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++)
        {
            TreeNode* root = new TreeNode(i);
            vector<TreeNode*> leftTrees = generateAns(start, end - 1);
            vector<TreeNode*> rightTrees = generateAns(start + 1, end);
            for (auto& leftTree : leftTrees) {
                for (auto& rightTree : rightTrees) {
                    root->left = leftTree;
                    root->right = rightTree;
                    res.emplace_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees2(int n) {
        vector<TreeNode*> res;
        vector<int> path;
        vector<bool> vis(n + 1, false);
        backtrace(res, path, vis, n);
        return res;
    }

    void backtrace(vector<TreeNode*>& res, vector<int>& path, vector<bool>& vis, int n) {
        if (path.size() == n) {
            TreeNode* root = genSearchTree(path);
            res.emplace_back(root);
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (vis[i])
                    continue;
                vis[i] = true;
                path.push_back(i);
                backtrace(res, path, vis, n);
                vis[i] = false;
                path.pop_back();
            }
        }
    }

    TreeNode* genSearchTree(vector<int>& path) {
        if (path.size() == 0)
            return nullptr;
        int n = path.size();
        TreeNode* root = nullptr;
        for (int x : path) {
            root = insertSerachTree(root, x);
        }
        return root;
    }

    TreeNode* insertSerachTree(TreeNode* root, int x) {
        if (root == nullptr)
            return new TreeNode(x);
        if (x > root->val)
            root->right = insertSerachTree(root->right, x);
        else
            root->left = insertSerachTree(root->left, x);
        return root;
    }
};

void levelOrder(TreeNode* root) {
    queue<TreeNode*> iq;
    iq.push(root);
    TreeNode* node;
    while (!iq.empty()) {
        node = iq.front();
        iq.pop();
        cout << node->val << ", ";
        if (node->left)
            iq.push(node->left);
        if (node->right)
            iq.push(node->right);
    }
    cout << endl;
}

int main(int argc, char const* argv []) {


    Solution so;
    auto res = so.generateTrees(4);
    for (auto root : res) {
        levelOrder(root);
    }

    return 0;
}