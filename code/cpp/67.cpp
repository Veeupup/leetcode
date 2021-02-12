#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 二进制加法
     * @param  {string} a :
     * @param  {string} b :
     * @return {string}   :
     */
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int m = a.size(), n = b.size();
        int carry = 0;
        int len = max(m, n);
        for (int i = 0; i < len; i++) {
            carry += i < m ? (a.at(i) == '1') : 0;
            carry += i < n ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }
        if (carry == 1) {
            ans += "1";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.addBinary("1010", "1011") << endl;

    return 0;
}