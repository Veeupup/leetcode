#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree cur.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if (tree == NULL)
            return {};
        vector<ListNode*> res;
        queue<TreeNode*> qu;
        qu.push(tree);
        while (!qu.empty()) {
            int n = qu.size();
            ListNode* last = nullptr;
            while (n--) {
                TreeNode* cur = qu.front();
                ListNode* node = new ListNode(cur->val);
                node->next = last;
                last = node;
                if (cur->right)
                    qu.push(cur->right);
                if (cur->left)
                    qu.push(cur->left);
                qu.pop();
            }
            res.push_back(last);
        }
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}