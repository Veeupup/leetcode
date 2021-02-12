#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 有一个问题，就是如果每次遇到都直接变为 0
     * 那么后面遍历的时候遇到那么就会产生误解
     * 所以需要用一个数据结构保存是否跳过
     * 
     * @param  {vector<vector<int>>} matrix : 输入矩阵
     */
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> zeroCols, zeroRows;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }
        for (int row : zeroRows) {
            for (int i = 0; i < n; i++) {
                matrix[row][i] = 0;
            }
        }
        for (int col : zeroCols) {
            for (int i = 0; i < m; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};

int main(int argc, char const* argv []) {

    vector<vector<int>> matrix {{1,1,1},
  {1,0,1},
  {1,1,1}};
    Solution so;
    so.setZeroes(matrix);
    for (auto vec : matrix) {
        cout << "[";
        for (int x : vec) 
            cout << x << ", ";
        cout << "]" << endl;
    }
        


    return 0;
}