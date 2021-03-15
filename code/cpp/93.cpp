#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * dfs + 回溯
     * @param  {string} s        :
     * @return {vector<string>}  :
     */
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        dfs(res, path, s, 0, 0);
        return res;
    }

    void dfs(vector<string>& res, string& path, string s, int begin, int depth) {
        int n = s.size();
        if (depth > 4)
            return;
        if (begin >= n && depth == 4) {
            res.push_back(path.substr(0, path.size() - 1));
        }
        else if (begin < n) {  // 最多只有三种可能，当前一个字符，当前两个，当前三个
            // 1. 一个字符一定可以
            char ch1 = s[begin];
            path.push_back(ch1);
            path.push_back('.');
            dfs(res, path, s, begin + 1, depth + 1);
            path.erase(path.size() - 2);

            if (begin + 1 < n) {
                char ch2 = s[begin + 1];
                if (ch1 != '0') {   // 两个字符，那么只要十位不为零就行
                    path += s.substr(begin, 2);
                    path.push_back('.');
                    dfs(res, path, s, begin + 2, depth + 1);
                    path.erase(path.size() - 3);
                }
            }

            if (begin + 2 < n) {
                char ch2 = s[begin + 1];
                char ch3 = s[begin + 2];
                int num = 100 * (ch1 - '0') + 10 * (ch2 - '0') + (ch3 - '0');
                if (num >= 100 && num <= 255) {
                    path += s.substr(begin, 3);
                    path.push_back('.');
                    dfs(res, path, s, begin + 3, depth + 1);
                    path.erase(path.size() - 4);
                }
            }
        }
    }
};

int main(int argc, char const* argv []) {

    string ip1 = "25525511135";
    Solution so;
    auto ips = so.restoreIpAddresses(ip1);
    for (string ip : ips) {
        cout << ip << endl;
    }

    ip1 = "0000";
    ips = so.restoreIpAddresses(ip1);
    for (string ip : ips) {
        cout << ip << endl;
    }

    ip1 = "1111";
    ips = so.restoreIpAddresses(ip1);
    for (string ip : ips) {
        cout << ip << endl;
    }

    ip1 = "101023";
    ips = so.restoreIpAddresses(ip1);
    for (string ip : ips) {
        cout << ip << endl;
    }


    return 0;
}