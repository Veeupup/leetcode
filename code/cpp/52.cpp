#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> queens(n, -1);
        unordered_set<int> cols;
        unordered_set<int> diaLeft;
        unordered_set<int> diaRight;
        int ans = 0;
        dfs(n, 0, cols, diaLeft, diaRight, ans);
        return ans;
    }

    void dfs(int n, int row, unordered_set<int>& cols, unordered_set<int>& diaLeft, unordered_set<int>& diaRight, int& ans) {
        if (row == n) {
            ans++;
        }
        else {
            for (int i = 0; i < n; i++) {
                if (cols.count(i))
                    continue;
                int dia1 = row - i;
                if (diaLeft.count(dia1))
                    continue;
                int dia2 = row + i;
                if (diaRight.count(dia2))
                    continue;

                cols.insert(i);
                diaLeft.insert(dia1);
                diaRight.insert(dia2);

                dfs(n, row + 1, cols, diaLeft, diaRight, ans);

                cols.erase(i);
                diaLeft.erase(dia1);
                diaRight.erase(dia2);
            }
        }
    }
};

int main(int argc, char const* argv []) {




    return 0;
}