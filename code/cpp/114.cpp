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
    /**
     * 如果只有三个节点，那么先序遍历 需要将保存当前节点的右子树，然后左子树变成右子树，然后右子树变成左子树的右子树
     * @param  {TreeNode*} root : 
     */
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        stack<TreeNode*> sta;
        sta.push(root);
        TreeNode* pre = nullptr;
        while (!sta.empty()) {
            TreeNode* cur = sta.top();
            sta.pop();
            if (pre != nullptr) {
                pre->left = nullptr;
                pre->right = cur;
            }
            TreeNode* leftNode = cur->left, * rightNode = cur->right;
            if (rightNode)
                sta.push(rightNode);
            if (leftNode)
                sta.push(leftNode);
            pre = cur;
        }
    }
};

int main(int argc, char const* argv []) {

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);

    node1->left = node2;
    node1->right = node5;
    node2->left = node3;
    node2->right = node4;
    node5->right = node6;
        
    Solution so;
    so.flatten(node1);
    
    TreeNode* root = node1;
    while (root) {
        printf("%d -> ", root->val);
        root = root->right;
    }
        

    return 0;
}