#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // vector<vector<int>> ans;
        // for (int i = 0; i <= rowIndex; i++) {
        //     vector<int> layer(i + 1);
        //     layer[0] = 1, layer[i] = 1;
        //     for (int j = 1; j < i; j++) {
        //         layer[j] = ans[i - 1][j] + ans[i - 1][j - 1];
        //     }
        //     ans.emplace_back(layer);
        // }
        // return ans[rowIndex];

        // vector<int> pre, cur;
        // for (int i = 0; i <= rowIndex; i++) {
        //     cur.resize(i + 1);
        //     cur[0] = cur[i] = 1;
        //     for (int j = 1; j < i; j++) {
        //         cur[j] = pre[j] + pre[j - 1];
        //     }
        //     pre = cur;
        // }
        // return pre;

        vector<int> row(rowIndex + 1);
        row[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    auto res = so.getRow(5);
    for (auto x : res) {
        cout << x << ", ";
    }
    cout << endl;

    return 0;
}