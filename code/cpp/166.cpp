#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 判断是否是循环小数
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0)   return "";
        if (numerator == 0) return "0";

        // 转换为 long long 防止越界
        typedef long long ll;
        ll num = static_cast<ll>(numerator);
        ll den = static_cast<ll>(denominator);

        // 处理正负号
        string res = "";
        if ((num > 0) ^ (den > 0)) res += "-";
        num = llabs(num), den = llabs(den);

        // 处理整数部分
        res += to_string(num / den);

        num %= den;
        if (num == 0) return res;
        res += "."; // 增加小数点，开始计算小数点之后的数字
        int idx = res.size() - 1;
        unordered_map<int, int> pos;
        while (num && pos.count(num) == 0) {
            pos[num] = ++idx;
            num *= 10;
            res += to_string(num / den);
            num %= den;
        }
        if (pos.count(num) == 1) {    // 出现了重复的数字
            int p = pos[num];
            res.insert(p, "(");
            res += ")";
        }
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}