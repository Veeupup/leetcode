#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     *
     * @param  {vector<vector<int>>} obstacleGrid :
     * @return {int}                              :
     */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1)
                    continue;
                if (obstacleGrid[i - 1][j - 1] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char const* argv []) {

    vector<vector<int>> arr = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
    Solution so;
    cout << so.uniquePathsWithObstacles(arr) << endl;

    return 0;
}