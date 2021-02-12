#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * dp[i][j] = dp[i-1][j] + dp[i][j-1]
     * dp[0][i] = 1, dp[i][0] = 1
     * @param  {int} m :
     * @param  {int} n :
     * @return {int}   :
     */
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            dp[i][1] = 1;
        }
        for (int i = 1; i <= n; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char const* argv []) {




    return 0;
}