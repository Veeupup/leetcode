#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 *  给定一个不含有重复值的数组 arr，找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置。
 *  返回所有位置相应的信息。
 */

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        arr[i] = x;
    }

    stack<int> sta;
    // 维护一个单调递增栈
    vector<pair<int, int>> help(n);
    for (int i = 0; i < n; i++) {
        while (!sta.empty() && arr[i] < arr[sta.top()]) {
            int top = sta.top();
            sta.pop();
            help[top].first = sta.empty() ? -1 : sta.top();
            help[top].second = i;
        }
        sta.push(i);
    }
    while (!sta.empty()) {
        int idx = sta.top();
        sta.pop();
        help[idx].first = sta.empty() ? -1 : sta.top();
        help[idx].second = -1;
    }
    for (int i = 0; i < n; i++) {
        cout << help[i].first << " " << help[i].second << endl;
    }
    return 0;
}
