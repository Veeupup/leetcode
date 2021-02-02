#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0)
            return 0;
        // 去除前置空格
        int idx = 0;
        while (s[idx] == ' ')
            ++idx;
        int flag = 1;
        if (s[idx] == '-')
            flag = -1;
        if (s[idx] == '+' || s[idx] == '-')
            ++idx;
        long res = 0, len = s.size();
        while (idx < len && isdigit(s[idx])) {
            res = res * 10 + s[idx] - '0';
            if (flag == 1 && res >= INT_MAX)
                return INT_MAX;
            if (flag == -1 && res * -1 <= INT_MIN)
                return INT_MIN;
            ++idx;
        }
        res *= flag;
        return int(res);
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.myAtoi("    -42") << endl;


    return 0;
}