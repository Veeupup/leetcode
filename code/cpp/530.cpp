#include <bits/stdc++.h> 
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        preOrder(root, vec);
        sort(vec.begin(), vec.end());
        vector<int>::iterator x = vec.begin(), y = x + 1;
        int ans = INT_MAX;
        while (y != vec.end())
        {
            ans = min(abs(*x-*y), ans);
            x++, y++;
        }
        return ans;
    }
private:
    void preOrder(TreeNode* root, vector<int>& vec) {
        if(root != NULL) {
            vec.emplace_back(root->val);
            preOrder(root->left, vec);
            preOrder(root->right, vec);
        }
    };
};

int main() {
    Solution *so = new Solution();
    

    return 0;
}
