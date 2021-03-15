#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
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
        for (int i = 0; i < n; i++) {
            if (dp[0][i]) {
                times[i] = 0;
            }
            else {
                for (int j = 0; j < i; j++) {
                    if (dp[j + 1][i]) {
                        times[i] = min(times[i], times[j] + 1);
                    }
                }
            }
        }
        return times[n - 1];
    }
};

int main(int argc, char const* argv []) {




    return 0;
}