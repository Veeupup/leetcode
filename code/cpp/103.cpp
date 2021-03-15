#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> iq;
        iq.push(root);
        bool left2right = true;
        while (!iq.empty()) {
            int len = iq.size();
            vector<int> layer(len);
            for (int i = 0; i < len; i++) {
                TreeNode* node = iq.front();
                iq.pop();
                layer[i] = node->val;
                if (node->left)
                    iq.push(node->left);
                if (node->right)
                    iq.push(node->right);
            }
            if (!left2right) {
                reverse(layer.begin(), layer.end());
            }
            res.emplace_back(layer);
            left2right = !left2right;
        }
        return res;
    }


    vector<vector<int>> zigzagLevelOrder2(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> iq;
        iq.push(root);
        bool left2right = true;
        while (!iq.empty()) {
            deque<int> layer;
            int len = iq.size();
            for (int i = 0; i < len; i++) {
                TreeNode* node = iq.front();
                iq.pop();
                if (left2right) {
                    layer.push_back(node->val);
                }
                else {
                    layer.push_front(node->val);
                }
                if (node->left) {
                    iq.push(node->left);
                }
                if (node->right) {
                    iq.push(node->right);
                }
            }
            res.emplace_back(vector<int>{layer.begin(), layer.end()});
            left2right = !left2right;
        }
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}