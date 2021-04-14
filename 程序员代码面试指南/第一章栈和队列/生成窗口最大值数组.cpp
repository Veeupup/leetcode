#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int>& arr) {
    int len = arr.size();
    if (n >= len) {
        return vector<int>{*max_element(arr.begin(), arr.end())};
    }
    queue<int> qu;
    vector<int> res;
    for (int i = 0; i < len; i++) {
        while (!qu.empty() && arr[qu.front()] <= arr[i])
            qu.pop();
        qu.push(i);
        if (qu.front() == i - n)
            qu.pop();   // 前面的值到期了
        if (i >= n - 1)
            res.push_back(arr[qu.front()]);
    }
    return res;
}

int main(int argc, char const* argv []) {

    vector<int> arr{ 4,3,5,4,3,3,6,7 };
    int n = 3;
    auto res = solve(3, arr);
    for (int x : res)
        cout << x << " ";

    return 0;
}