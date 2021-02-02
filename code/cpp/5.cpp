#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 最长回文子串
     *
     *  1. 暴力法
     *      对于 n^2 个子串，分别进行判断，直到长度最长的那一个
     *  2. 子串问题，应该应用双指针
     *      
     * 
     * @param  {string} s :
     * @return {string}   :
     */
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        
        bool dp[1010][1010]; // 记录是否是回文串
        for (int i = 0; i < s.size(); i++)  
            dp[i][i] = true;    // 单个字符一定是回文串
        
        int begin = 0, maxLen = 1;
        
        for (int j = 1, len = s.size(); j < len; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (s[i] != s[j])
                    dp[i][j] = false;
                else {
                    if (j - i <= 2)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i - 1][j + 1];
                }
                
                if (dp[i][j] && j - i + 1 > maxLen) {
                    begin = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(begin, maxLen);
    }

    // 暴力法
    string longestPalindrome2(string s) {
        if (s.size() <= 1)
            return s;
        string res;
        for (int i = 0, len = s.size(); i < len; i++) {
            for (int j = 1; j + i <= len; j++) {
                string temp_str = s.substr(i, j);
                if (isSym(temp_str))
                    res = res.size() >= temp_str.size() ? res : temp_str;
                // cout << s.substr(i, j) << endl;
            }
        }
        return res;
    }

    bool isSym(string& s) {
        if (s.size() <= 1)
            return true;
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            ++left, --right;
        }
        return true;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.longestPalindrome2("abcdc") << endl;
    


    return 0;
}