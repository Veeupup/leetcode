#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 回溯法
     *  从一个长度开始递归回溯，直到某个长度不再是回文串，
     * @param  {string} s                :
     * @return {vector<vector<string>>}  :
     */
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        if (n == 0)
            return ans;
        // 使用动态规划提前优化
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int right = 0; right < n; right++) {
            for (int left = 0; left <= right; left++) {
                if (s[left] == s[right] && (right - left <= 2 || dp[left + 1][right - 1]))
                    dp[left][right] = 1;
            }
        }
        backtrace(s, 0, dp);
        return ans;
    }

    void backtrace(string s, int begin, vector<vector<int>>& dp) {
        int n = s.size();
        if (n == begin) {
            ans.push_back(path);
        }
        else {
            for (int len = 1; len + begin <= n; len++) {
                if (dp[begin][begin + len - 1]) {
                    string tmp = s.substr(begin, len);
                    path.push_back(tmp);
                    backtrace(s, begin + len, dp);
                    path.pop_back();
                }
            }
        }
    }

    bool isSym(string& s) {
        for (int i = 0, n = s.size() - 1; i < n; i++, n--) {
            if (s[i] != s[n])
                return false;
        }
        return true;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    auto ans = so.partition("aab");
    for (auto vec : ans) {
        cout << "[";
        for (auto str : vec) {
            cout << str << ", ";
        }
        cout << "]";
    }

    return 0;
}