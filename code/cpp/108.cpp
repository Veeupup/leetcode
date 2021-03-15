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
     * 构造一个平衡二叉树
     * 对于有序数组，将数组的中间位置当作根节点最好
     * @param  {vector<int>} nums :
     * @return {TreeNode*}        :
     */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return nullptr;
        return buildTree(nums, 0, n - 1);
    }

    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, start, mid - 1);
        root->right = buildTree(nums, mid + 1, end);
        return root;
    }

};

int main(int argc, char const* argv []) {




    return 0;
}