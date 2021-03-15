#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            sum.resize(m, vector<int>(n + 1));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
                }
            }
        }

        // int m = matrix.size();
        // if (m == 0)
        //     return;
        // int n = matrix[0].size();
        // sum.resize(m);
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (j == 0)
        //             sum[i].push_back(matrix[i][j]);
        //         else
        //             sum[i].push_back(sum[i][j - 1] + matrix[i][j]);
        //     }
        // }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];

        // if (row1 > row2 || col1 > col2)
        //     return -1;
        // int ans = 0;
        // for (int i = row1; i <= row2; i++) {
        //     if (col1 == 0)
        //         ans += sum[i][col2];
        //     else
        //         ans += (sum[i][col2] - sum[i][col1 - 1]);
        // }
        // return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */



int main(int argc, char const* argv []) {




    return 0;
}