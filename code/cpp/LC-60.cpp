#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    /**
     * n 个骰子，i 代表和为第 i 小的元素的概率
     * 范围：
     * n, n+1, n+2, ..., 6*n
     * 这是一个古典概率的问题，用可能性来做，一共有 pow(6, n) 种可能
     * 动态递归问题，递推公式为：
     * 
     * 
     * @param  {int} n           : 
     * @return {vector<double>}  : 
     */
    vector<double> dicesProbability(int n) {
        int dp[13][70];
        memset(dp, 0, sizeof(dp));
        // 边界情况，只有一个骰子
        for (int i = 1; i <= 6; i++)
            dp[1][i] = 1;  
        for (int i = 2; i <= n; i++) {  // 自底向上，计算 2～n 个骰子总点数
            for (int j = i; j <= 6 * i; j++) {  // i 个 骰子 的总点数
                for (int cur = 1; cur <= 6; cur++)  // 当前骰子的点数
                {
                    if (j - cur <= 0)
                        break;
                    dp[i][j] += dp[i-1][j-cur];
                }
            }
        }
        vector<double> res;
        int all = pow(6, n);
        for (int i = n; i <= 6 * n; i++) {
            res.emplace_back(dp[n][i] * 1.0 / all);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{ 
    Solution so;
    int n = 3;
    auto res = so.dicesProbability(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << i+3 << " : " << res[i] << endl;
    }
    
    

    
    return 0;
}