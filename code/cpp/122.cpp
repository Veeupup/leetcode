#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    /**
     * 不限制股票购买的次数
     * 
     * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
     * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
     *              = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i])
     * 因为 k = +∞，所以 k = k - 1
     * 发现与 k 没有关系
     * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
     * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
     * 
     * dp[-1][0] = 0, dp[-1][1] = MIN_MAX
     * 
     * @param  {vector<int>} prices : 股票价格
     * @return {int}                : 最大利润
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int dp_i_0 = 0, dp_i_1 = -1 * prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
};

int main(int argc, char const *argv[])
{ 

    int arr[] = {7,1,5,3,6,4};
    vector<int> prices(arr, arr + 6);
    Solution so;
    cout << so.maxProfit(prices) << endl;
    
    return 0;
}