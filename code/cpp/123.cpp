#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     *
     * dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i])
     * dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i])
     * dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
     * dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i])
     *
     * dp_i20 = max(dp_i20, dp_i21 + prices[i])
     * dp_i21 = max(dp_i21, dp_i10 - prices[i])
     * dp_i10 = max(dp_i10, dp_i11 + prices[i])
     * dp_i11 = max(dp_i11, -prices[i])
     *
     * @param  {vector<int>} prices :
     * @return {int}                :
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int dp_i20 = 0, dp_i21 = INT_MIN, dp_i10 = 0, dp_i11 = INT_MIN;
        for (int price : prices) {
            dp_i20 = max(dp_i20, dp_i21 + price);
            dp_i21 = max(dp_i21, dp_i10 - price);
            dp_i10 = max(dp_i10, dp_i11 + price);
            dp_i11 = max(dp_i11, -1 * price);
        }
        return dp_i20;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}