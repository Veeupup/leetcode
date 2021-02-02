#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 打家劫舍
     *
     * dp[i] = max(dp[i+1], nums[i] + dp[i+2])
     *
     * @param  {vector<int>} nums :
     * @return {int}              :
     */
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int len = nums.size();
        // vector<int> dp(len + 2);
        // for (int i = len - 1; i >= 0; i--) {
        //     dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        // }
        int dp_i, dp_i_1 = 0, dp_i_2 = 0;
        for (int i = len - 1; i >= 0; i--) {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}