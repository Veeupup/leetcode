#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // dp[i] 代表到达 i 位置所需要的最少的次数
    // dp[0] = 0, 
    // dp[i] = INT_MAX, dp[j] = min(dp[j], dp[i] + 1)
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n)
                    dp[i+j] = min(dp[i+j], dp[i] + 1);
            }
        }
        return dp[n-1];
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}