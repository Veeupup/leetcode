#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> layer(i + 1);   // 每层 i + 1 个数字
            layer[0] = 1, layer[i] = 1;
            for (int j = 1; j < i; j++) {
                layer[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.emplace_back(layer);
        }
        return ans;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    auto ans = so.generate(5);
    for (auto layer : ans) {
        for (auto x : layer) {
            cout << x << ", ";
        }
        cout << endl;
    }


    return 0;
}