#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     *  找到规律
     *      1. matrix[row][col] => matrix[col][n - row - 1]
     *      2. matrix[col][n - row - 1] => matrix[n - row - 1][n - col - 1]
     *      3. matrix[n - row - 1][n - col - 1] => matrix[n - col - 1][row]
     *      4. matrix[n - col - 1][row ] => matrix[row][col]
     *  那么，我们将进行四次旋转
     *      int temp = matrix[row][col];
     *      matrix[row][col] = matrix[n - col - 1][row]
     *      matrix[n - col - 1][row] =  matrix[n - row - 1][n - col - 1]
     *      matrix[n - row - 1][n - col - 1] = matrix[col][n - row - 1]
     *      matrix[col][n - row - 1] = temp
     *
     **/
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int row = 0; row < n / 2;++row) {
            for (int col = 0; col < (n + 1) / 2; ++col) {
                int tmp = matrix[row][col];
                matrix[row][col] = matrix[n - col - 1][row];
                matrix[n - col - 1][row] = matrix[n - row - 1][n - col - 1];
                matrix[n - row - 1][n - col - 1] = matrix[col][n - row - 1];
                matrix[col][n - row - 1] = tmp;
            }
        }
    }
};

class Solution2 {
public:
    // 找到规律，其实也就是正方形顺时针旋转, 按照层来，一层一层旋转，采用递归
    // 先占用额外空间，如果有 N，0 ~ N/2
    vector<vector<int>> copy;
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        copy = matrix;
        for (int i = 0; i < n / 2; ++i) {
            rotate(matrix, i, n - i * 2);
        }
    }

    void rotate(vector<vector<int>>& matrix, int start, int len) {
        int end = start + len - 1;
        // 上方 由 左边竖着的变
        for (int i = 0; i < len; ++i) {
            matrix[start][start + i] = copy[end - i][start];
        }
        // 右边 由 上方的变
        for (int i = 0; i < len; ++i) {
            matrix[start + i][end] = copy[start][start + i];
        }
        // 下方 由 右边的变
        for (int i = 0; i < len; ++i) {
            matrix[end][start + i] = copy[end - i][end];
        }
        for (int i = 0; i < len; ++i) {
            matrix[start + i][start] = copy[end][start + i];
        }
    }
};

int main(int argc, char const* argv []) {




    return 0;
}