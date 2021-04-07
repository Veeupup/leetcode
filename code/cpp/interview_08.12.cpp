#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_set<int> diaLeft, diaRight, cols;
    vector<vector<string>> res;
public:
    // 通过回溯法来找到 n 皇后的解
    // 找到每一行可能的解
    void dfs(vector<int>& rows, int c_row, const int n) {
        if (c_row == n) {
            generateBoard(rows, n);
            return;
        }
        for (int i = 0; i < n; i++) {   // 这里是找的列
            if (cols.count(i))
                continue;
            int dia_1 = c_row - i;
            if (diaLeft.count(dia_1))
                continue;
            int dia_2 = c_row + i;
            if (diaRight.count(dia_2))
                continue;
            rows[c_row] = i;
            cols.insert(i);
            diaLeft.insert(dia_1);
            diaRight.insert(dia_2);
            dfs(rows, c_row + 1, n);

            cols.erase(i);
            diaLeft.erase(dia_1);
            diaRight.erase(dia_2);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> rows(n);    // 每一行开始找
        dfs(rows, 0, n);
        return res;
    }

    void generateBoard(vector<int>& rows, const int n) {
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            string line(n, '.');
            line[rows[i]] = 'Q';
            ans.push_back(line);
        }
        res.push_back(ans);
    }
};

int main(int argc, char const* argv []) {




    return 0;
}