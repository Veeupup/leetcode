#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 从右上角开始搜索
     * @param  {vector<vector<int>>} matrix :
     * @param  {int} target                 :
     * @return {bool}                       :
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                j--;
            else if (matrix[i][j] < target)
                i++;
        }
        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        int pivotIdx, pivotEle;
        while (left <= right) {
            pivotIdx = left + ((right - left) >> 1);
            pivotEle = matrix[pivotIdx / n][pivotIdx % n];
            if (pivotEle > target)
                right = pivotIdx - 1;
            else if (pivotEle < target)
                left = pivotIdx + 1;
            else if (pivotEle == target)
                return true;
        }
        return false;
    }

};

int main(int argc, char const* argv []) {




    return 0;
}