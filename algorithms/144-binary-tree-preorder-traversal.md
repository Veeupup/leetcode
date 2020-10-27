# [144. 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)

# Solution

递归解法：

```c++
void preorder(TreeNode* root, vector<int>& ans) {
    if (root == nullptr)
        return;
    ans.emplace_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
```

迭代解法：

```c++
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == nullptr)
        return ans;

    stack<TreeNode*> myS;
    TreeNode* node = root; 

    while (!myS.empty() || node != nullptr) {
        while (node != nullptr) {
            ans.emplace_back(node->val);
            myS.push(node);
            node = node -> left;
        }

        node = myS.top();
        myS.pop();
        node = node -> right;
    }
    return ans;
}
```

