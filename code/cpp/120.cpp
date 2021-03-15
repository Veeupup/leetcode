#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 动态规划
     *  f[i][j] = min(f[i-1][j-1], f[i-1][j]) + c[i][j]
     *  f[i][0] = 0
     *
     * @param  {vector<vector<int>>} triangle :
     * @return {int}                          :
     */
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size();
        // vector<vector<int>> dp(n + 1, n + 1);
        // dp[0][0] = triangle[0][0];
        // for (int i = 1; i < n; i++) {
        //     dp[i][0] = dp[i - 1][0] + triangle[i][0];
        //     for (int j = 1; j < i; j++) {
        //         dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        //     }
        //     dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        // }
        // return *min_element(dp[n - 1].begin(), dp[n - 1].end());

        int n = triangle.size();
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        return *min_element(dp.begin(), dp.end());
    }

    /**
     * 三角形最短路径
     *  思路：回溯 + 剪枝
     * @param  {vector<vector<int>>} triangle : 三角形数组
     * @return {int}                          : 最小路径和
     */
    int minimumTotal2(vector<vector<int>>& triangle) {
        int min_val = INT_MAX;  // 初始化最小路径和
        backtrace(triangle, 0, 0, min_val, 0);
        return min_val;
    }

    void backtrace(vector<vector<int>>& triangle, int depth, int index, int& min_val, int sum) {
        int n = triangle.size();
        if (depth == n) {
            min_val = min(min_val, sum);
        }
        else {
            int now_val = triangle[depth][index];
            if (sum + now_val > min_val) {    // 剪枝
                return;
            }
            sum += now_val;
            backtrace(triangle, depth + 1, index, min_val, sum);
            backtrace(triangle, depth + 1, index + 1, min_val, sum);
            sum -= now_val;
        }
    }
};

int main(int argc, char const* argv []) {




    return 0;
}