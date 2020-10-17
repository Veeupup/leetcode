#include <bits/stdc++.h> 
using namespace std;

class Solution {
public: 
    void dfs(int row[], int cnt, int& ans, int n) {
        if (cnt == n) {
            ans++;
            return;
        }else {
            for (int i = 0; i < n; i++)
            {
                int j = 0;
                for (j = 0; j < cnt; j++)
                {
                    if (row[j] == i || abs(cnt - j) == abs(row[j] - i))
                        break;
                }
                if (j == cnt) {
                    row[cnt] = i;
                    dfs(row, cnt+1, ans, n);
                }
            }
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        int row[n];
        memset(row, 0, sizeof(row));
        dfs(row, 0, ans, n);
        return ans;
    }
};

int main() {
    Solution *so = new Solution();


    return 0;
}
