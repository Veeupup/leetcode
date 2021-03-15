#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 应该使用贪心，从前往后 找到 left 能够到达的最远的地方，然后从 right 开始找，如果能到末尾，那么直接返回，否则再次递归
    bool checkOnesSegment(string s) {
        int n = s.size();
        if (n <= 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int right = 0; right < n; ++right) {
            for (int left = 0; left <= right; ++left) {
                if (s[left] == s[right] && (right - left <= 2 || dp[left + 1][right - 1]))
                    dp[left][right] = 1;
            }
        }
        vector<int> times(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            if (dp[0][i]) {
                times[i] = 0;
            }            
            else {
                for (int j = 1; j < i; j++) {
                    if (dp[j][i]) {
                        times[i] = min(times[i], times[j-1] + 1);
                    }
                }
            }
        }
        return times[n-1];
    }
};

int main(int argc, char const* argv []) {




    return 0;
}