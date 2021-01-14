#include <bits/stdc++.h>
using namespace std;

/**
* 判断输入的是否是二叉搜索树的后序遍历
    二叉搜索树的后序遍历的性质 left right mid
    左边的节点一定比中间节点小，右边的节点一定比中间节点大

    最后的节点一定能找到一个区分的点，那么就是将数组恰好分成左右两边，
    左边的比它小，右边的比他大
    如果满足这个性质，那么继续递归



*/

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return isPostOrder(postorder, 0, postorder.size() - 1);
    }

    bool isPostOrder(vector<int>& postorder, int start, int end) {
        if (start >= end)
            return true;
        int key = postorder[end];
        int post = start;
        while (post < end && postorder[post] < key)
        {
            post++;
        }
        for (int i = post; i < end; i++) {
            if (postorder[i] < key)
                return false;
        }
        return isPostOrder(postorder, start, post - 1)
            && isPostOrder(postorder, post, end - 1);
    }
};

int main() {
    Solution so;
    // int arr[] = {1,6,3,2,5};
    // int arr[] = {1,3,2,6,5};
    int arr[] = { 1,2,5,10,6,9,4,3 };
    vector<int> iv(arr, arr + 8);

    cout << so.verifyPostorder(iv) << endl;

    return 0;
}