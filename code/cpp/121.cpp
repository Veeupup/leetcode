#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    /**
     * 买卖股票的最大利润
     * dp[i][k][1/0] 代表 第 i 天，k 为交易次数，1 代表拥有股票，0 代表没有股票
     * 0 <= i <= n-1, 1 <= k <= K,
     * 那么
     * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]); 前一天不买股票 / 前一天买了股票 今天卖
     * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]); 前一天买了 / 前一天没买，今天买了
     * 初始状态
     * dp[-1][k][0] = 0, 开始之前不拥有为 0，    dp[-1][k][1] = INT_MIN, 开始之前就拥有不可能
     * dp[i][0][0] = 0, k从1开始，0代表不能交易， dp[i][0][1] = INT_MIN, 不能交易不能持有股票
     *
     * 在这个地方，K = 1, 所以 k = 1
     * dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
     * dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]);
     *              = max(dp[i-1][1][1], -prices[i]);
     * 与 k 无关，所以缩减状态
     * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
     * dp[i][1] = max(dp[i-1][1], -prices[i]);
     *
     * dp[-1][0] = 0, dp[-1][1] = INT_MIN
     *
     * @param  {vector<int>} prices :
     * @return {int}                :
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        // 标准 dp 数组
        // vector<vector<int>> dp(prices.size(), vector<int>(2));
        // int n = prices.size();
        // dp[0][0] = 0, dp[0][1] = -1 * prices[0];
        // for (int i = 1; i < n; ++i) {
        //     dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        //     dp[i][1] = max(dp[i - 1][1], -1 * prices[i]);
        // }
        // return dp[n - 1][0];
        int dp_i_0 = 0, dp_i_1 = -1 * prices[0];
        for (int i = 0, n = prices.size(); i < n; i++)         {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, -1 * prices[i]);
        }
        return dp_i_0;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1)
            return 0;
        int best = 0, low = prices[0], high = prices[0];
        for (int i = 1; i < n; i++)
        {
            best = max(best, prices[i] - low);
            low = min(low, prices[i]);
            high = max(high, prices[i]);
        }
        return best;
    }

    int maxProfit(vector<int>& prices) {
                
    }
            
};

int main() {
    Solution* so = new Solution();

    vector<int> arr{ 7,1,5,3,6,4 };
    cout << so->maxProfit(arr) << endl;

    arr = { 7,6,4,3,1 };
    cout << so->maxProfit(arr) << endl;

    return 0;
}
