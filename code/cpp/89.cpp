#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 使用字符串保存当前的编码，每次变动一个位置的字符，
     * @param  {int} n        : 格雷编码的位数
     * @return {vector<int>}  : 符合条件的一组格雷编码
     */
    vector<int> grayCode2(int n) {
        if (n == 0)
            return {};
        vector<int> res{ 0 };
        int head = 1;
        for (int i = 0; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.emplace_back(res[j] + head);
            }
            head <<= 1;
        }
        return res;
    }

    vector<int> grayCode(int n) {
        if (n == 0)
            return {};
        vector<int> res;
        set<string> codes;
        string code = string(n, '0');

        res.push_back(0);
        codes.insert(code);
        for (int i = 0, count = pow(2, n); i < count; i++) {
            // 从末尾开始改变格雷编码，如果不存在则加入
            string tmp = code;
            for (int j = n - 1; j >= 0; j--) {
                // 如果已经存在，那么尝试改变该位置的字符
                tmp = code;
                if (code[j] == '1')
                    tmp[j] = '0';
                else
                    tmp[j] = '1';
                if (codes.find(tmp) == codes.end()) {
                    codes.insert(tmp);
                    code = tmp;
                    res.emplace_back(binToInt(tmp));
                    break;
                }
            }
        }
        return res;
    }

    int binToInt(string& str) {
        int res = 0;
        int x = 1;
        for (int i = str.size() - 1; i >= 0; i--) {
            if (str[i] == '1')
                res += x;
            x <<= 1;
        }
        return res;
    }
};


int main(int argc, char const* argv []) {

    Solution so;
    auto res = so.grayCode2(3);
    for (int x : res) {
        cout << x << ", ";
    }
    cout << endl;

    return 0;
}