#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int idx = 0;
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
            });
        int len = strs[0].size();
        bool flag = false;
        for (; idx < len; idx++) {
            char tmp = strs[0][idx];
            for (string str : strs) {
                if (str[idx] != tmp) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        return strs[0].substr(0, idx);
    }
    
    string longestCommonPrefix2(vector<string>& strs) {
        if (strs.empty())
            return "";
        sort(strs.begin(), strs.end());
        string front = strs.front(), back = strs.back();
        int i, num = min(front.size(), back.size());
        for (i = 0; i < num && front[i] == back[i];i++);
        return front.substr(0, i);
    }
};

int main(int argc, char const* argv []) {




    return 0;
}