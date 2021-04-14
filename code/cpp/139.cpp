#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // dp[i] = dp[j] && check(s[j, i-1])
    // dp[0] = true
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (string word : wordDict)
            words.insert(word);
        int n = s.size();
        vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i;j++) {
                if (dp[j] && words.find(s.substr(j, i - j)) != words.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main(int argc, char const* argv []) {




    return 0;
}