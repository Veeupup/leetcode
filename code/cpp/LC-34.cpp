#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
*  本题是一个搜索题，需要 dfs
    需要记录下当前的路径，最终递归的条件是到和为 sum
    dfs + 减枝
*/

class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return res;
    }
    void dfs(TreeNode* root, int sum) {
        if (!root)
            return;
        sum -= root->val;
        tmp.emplace_back(root->val);
        
        if (sum == 0 && !root->left && !root->right)
            res.emplace_back(tmp);
        dfs(root->left, sum);
        dfs(root->right, sum);
        tmp.pop_back();
    }
};

int main() {



    return 0;
}