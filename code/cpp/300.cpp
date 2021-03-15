#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 最长上升子序列
     *  dp[i] 代表到下标 i 的最大上升子序列的长度
     *  从前往后，O()n^2
     *
     * @param  {vector<int>} nums :
     * @return {int}              :
     */
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)
            return n;
        vector<int> dp(n, 1);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}