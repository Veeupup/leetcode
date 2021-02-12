#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 动态规划
     *
     * dp[n] = dp[n-1] + dp[n-2]
     *
     * @param  {int} n :
     * @return {int}   :
     */
    int climbStairs(int n) {
        if (n == 1 || n == 2)
            return n;
        int ans = -1, pre_pre = 1, pre = 2;
        for (int i = 3; i <= n; i++) {
            ans = pre_pre + pre;
            pre_pre = pre;
            pre = ans;
        }
        return ans;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    for (int i = 1; i < 10; i++) {
        cout << so.climbStairs(i) << endl;
    }


    return 0;
}