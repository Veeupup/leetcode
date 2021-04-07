#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 01 完全背包问题
    // dp[i] = min(dp[i], dp[i - coins[i]] + 1)
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            // 这个时候应该测试所有的硬币数量，看谁的最小
            for (int j = 0; j < n; ++j) {
                if (i - coins[j] < 0)
                    break;  // 当前的钱数 - 当前的硬币大小小于 0 指定不行了
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}