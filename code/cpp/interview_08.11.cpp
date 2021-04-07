#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int EX = 1e9+7;
public:
    // n 分有多少种表示方法，青蛙跳台阶的变形
    // dp[n] = dp[n-1] + dp[n-5] + dp[n-10] + dp[n-25]
    // dp[0] = 1,
    // 这个是错误的，因为这是一个完全背包问题，不是青蛙跳台阶，青蛙跳台阶是排列数，也就是不同排列可能的次数，1 5 和  5 1 不同
    // 但是这个是组合数，也就是说 1 5 和 5 1 相同，所以不能这么做
    // dp[i][j] = dp[i-1][j] + dp[i][j-nums[i]], 不使用第 i 枚硬币，和使用第 i 枚硬币
    // dp[i][0] = 1
    int waysToChange(int n) {
        vector<vector<int>> dp(5, vector<int>(n+1, 0));
        for (int i = 0; i < 5; i++)
            dp[i][0] = 1;
        vector<int> coins {1, 5, 10, 25};
        for (int i = 1; i <= 4; i++) {
            int coin = coins[i-1];
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= coin) {
                    dp[i][j] += dp[i][j-coin];
                }
                dp[i][j] %= EX;
            }
        }
        return dp[4][n];
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}