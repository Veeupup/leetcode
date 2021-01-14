#include <bits/stdc++.h>
using namespace std;

/**
* 考虑栈的弹出可能形式，
* 栈插入之后弹出的形式可能有？
*   使用一个模拟栈来模仿操作，先按照 pushed 数组中插入，
*   每次插入之后检查是否是 poped 的顶部元素是否等于刚插入的，如果是，那么就 pop
*   直到插入的序列全部结束，此时 push 和 pop 同步进行，如果元素相同那么就pop，否则就return false
*   最后check stack 中是否为空
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size())
            return false;
        stack<int> ista;
        int idx = 0;
        for (auto x : pushed) {
            ista.push(x);
            // 从 if 修改为 while，因为
            while (!ista.empty() && popped[idx] == ista.top()) {
                idx++;
                ista.pop();
            }
        }
        return ista.empty();
    }
};

int main() {
    Solution so;

    // int arr1[] = { 1,2,3,4,5 }, arr2[] = { 4,5,3,2,1 };
    // vector<int> pushed(arr1, arr1 + 5);
    // vector<int> popped(arr2, arr2 + 5);
    // cout << so.validateStackSequences(pushed, popped) << endl;

    int arr1[] = { 2, 1, 0 }, arr2[] = { 1, 2 ,0 };
    vector<int> pushed(arr1, arr1 + 3);
    vector<int> popped(arr2, arr2 + 3);
    cout << so.validateStackSequences(pushed, popped) << endl;

    return 0;
}