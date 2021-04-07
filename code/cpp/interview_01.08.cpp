#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. 使用 pair 保存所有是 0 的位置，之后再进行遍历清空
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();
        vector<pair<int, int>> zeroPoints;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0)
                    zeroPoints.push_back({i, j});
            }
        }
        for (const auto& point : zeroPoints) {
            int row = point.first, col = point.second;
            for (int i = 0; i < m; ++i) {
                matrix[i][col] = 0;
            }
            for (int i = 0; i < n; ++i) {
                matrix[row][i] = 0;
            }
        }
    }
};

int main(int argc, char const* argv []) {




    return 0;
}