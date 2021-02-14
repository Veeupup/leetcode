#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 动态规划：
     *
     * dp[i] 代表以 i 为结尾，一共有多少种解法, 这是开区间 dp[1]
     *
     * dp[i] = dp[i-1] / dp[i-2]
     *
     * @param  {string} s :
     * @return {int}      :
     */
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        if (s[0] == '0')
            return 0;
        int pre = 1, cur = 1;
        for (int i = 1; i < n; i++) {
            int tmp = cur;
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    cur = pre;
                else
                    return 0;
            }
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                cur = cur + pre;
            }
            pre = tmp;
        }
        return cur;
    }

    int numDecodings2(string s) {
        if (s.size() == 0)
            return 0;
        int cnt = 0;
        backtrace(s, cnt, 0);
        return cnt;
    }

    void backtrace(const string& s, int& cnt, int start) {
        int len = s.size();
        if (start == len) {
            cnt++;
        }
        else {
            char nowChar = s[start];
            if (nowChar >= '1' && nowChar <= '9')
                backtrace(s, cnt, start + 1);

            if (start + 1 < len) {
                char nextChar = s[start + 1];
                int num = 10 * (nowChar - '0') + (nextChar - '0');
                if (num >= 10 && num <= 26)
                    backtrace(s, cnt, start + 2);
            }
        }
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.numDecodings("12") << endl;
    cout << so.numDecodings("226") << endl;
    cout << so.numDecodings("0") << endl;
    cout << so.numDecodings("06") << endl;


    return 0;
}