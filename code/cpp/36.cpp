#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 数独的有效性，
     * 验证一个数独是否有效，需要验证三个规则
     *
     *
     * @param  {vector<vector<char>>} board :
     * @return {bool}                       :
     */
    bool isValidSudoku(vector<vector<char>>& board) {
        // 
        int col[9][10] = { 0 };
        int row[9][10] = { 0 };
        int box[9][10] = { 0 };
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int curNum = board[i][j] - '0';
                if (col[i][curNum]) // 第 i 行是否重复
                    return false;
                if (row[j][curNum]) // 第 j 列是否重复
                    return false;
                if (box[j / 3 + (i / 3) * 3][curNum])
                    return false;
                col[i][curNum] = 1;
                row[j][curNum] = 1;
                box[j / 3 + (i / 3) * 3][curNum] = 1;
            }
        }
        return true;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    vector<vector<char>> board{
  {"5","3",".",".","7",".",".",".","."},
  {"6",".",".","1","9","5",".",".","."},
  {".","9","8",".",".",".",".","6","."},
  {"8",".",".",".","6",".",".",".","3"},
  {"4",".",".","8",".","3",".",".","1"},
  {"7",".",".",".","2",".",".",".","6"},
  {".","6",".",".",".",".","2","8","."},
  {".",".",".","4","1","9",".",".","5"},
  {".",".",".",".","8",".",".","7","9"} };



    return 0;
}