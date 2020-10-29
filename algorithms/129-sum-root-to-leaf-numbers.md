[129. 求根到叶子节点数字之和](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/)

简单DFS

```c++
// dfs 即可
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int nowSum = 0, ans = 0;
        dfs(root, nowSum, ans);
        return ans;
    }

    void dfs(TreeNode* root, int nowSum, int& ans) {
        if (root == NULL)
            return;
        nowSum = nowSum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
           ans += nowSum;
           return;
        }
        if (root->left != NULL)
            dfs(root->left, nowSum, ans);
        if (root->right != NULL)
            dfs(root->right, nowSum, ans);
    }
};
```

