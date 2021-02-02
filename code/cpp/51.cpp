#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queens(n, -1);
        set<int> cols;
        set<int> diaLeft;
        set<int> diaRight;
        backtrace(res, cols, diaLeft, diaRight, 0, n, queens);
        return res;
    }

    void backtrace(vector<vector<string>>& res, set<int>& cols, set<int>& diaLeft, set<int>& diaRight, int row, int n, vector<int>& queens) {
        if (row == n) {
            generateBoard(res, queens, n);
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (cols.count(i))    // 列已经存在
                    continue;
                int dia1 = i - row;
                if (diaLeft.count(dia1))
                    continue;
                int dia2 = i + row;
                if (diaRight.count(dia2))
                    continue;

                queens[row] = i;
                cols.insert(i);
                diaLeft.insert(dia1);
                diaRight.insert(dia2);

                backtrace(res, cols, diaLeft, diaRight, row + 1, n, queens);

                queens[row] = -1;
                cols.erase(i);
                diaLeft.erase(dia1);
                diaRight.erase(dia2);
            }
        }
    }

    void generateBoard(vector<vector<string>>& res, vector<int>& queens, int n) {
        vector<string> board;
        for (int i = 0; i < n; ++i) {
            string row(n, '.');
            row[queens[i]] = 'Q';
            board.emplace_back(row);
        }
        res.emplace_back(board);
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    auto res = so.solveNQueens(4);
    for (auto board : res) {
        for (auto row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}