#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
    int getLen(ListNode* head) {
        int ret = 0;
        for (;head != nullptr; ++ret, head = head->next);
        return ret;
    }

    TreeNode* sortedListToBST2(ListNode* head) {
        int len = getLen(head);
        return buildMyTree(head, 0, len - 1);
    }

    TreeNode* buildMyTree(ListNode*& head, int left, int right) {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode();
        root->left = buildMyTree(head, left, mid-1);
        root->val = head->val;
        head = head->next;
        root->right = buildMyTree(head, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode* node = head;
        while (node) {
            nums.push_back(node->val);
            node = node->next;
        }
        return buildTree(nums, 0, nums.size() - 1);
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