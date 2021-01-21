#include <bits/stdc++.h>
using namespace std;

/**
 *  对于 m*n 的棋盘，dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]);
 * 
*/

class Solution
{
public:
    int endX, endY;
    // 多开一点存储空间来减少代码的复杂度
    int dp[201][201] = {0};
    int maxValue(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= cols; j++)
            {
                dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[rows][cols];
    }

    int maxValue2(vector<vector<int>> &grid)
    {
        int res = 0, nowVal = 0;
        endX = grid.size(), endY = grid[0].size();
        dfs(grid, 0, 0, nowVal, res);
        return res;
    }

    void dfs(vector<vector<int>> &grid, int x, int y, int nowVal, int &res)
    {
        if (x > endX || y > endY)
            return;
        nowVal += grid[x][y];
        if (x == endX && y == endY)
        {
            res = max(res, nowVal);
            return;
        }
        nowVal += grid[x][y];
        dfs(grid, x + 1, y, nowVal, res);
        dfs(grid, x, y + 1, nowVal, res);
    }
};

int main()
{

    return 0;
}