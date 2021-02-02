#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    /**
     * 字符串转为整数
     * 1. 去除空格，判断是否是 + - 或者整数开头
     * 2. 如果是一直向后增加计算每个值，直到第一个非数字或者结束
     * @param  {string} str : 
     * @return {int}        : 
     */
    int strToInt(string str) {
        int index = 0;
        while (str[index] == ' ')
            ++index;
        bool positive = true;
        if (str[index] == '-') positive = false;
        if (str[index] == '-' || str[index] == '+') ++index;
        long res = 0;
        while (index < str.size() && str[index] >= '0' && str[index] <= '9') {
            res = (res * 10) + str[index++] - '0';
            if (res >= INT_MAX && positive) return INT_MAX;
            if (res > INT_MAX && !positive) return INT_MIN;
        }
        return res * positive;
    }
};

int main(int argc, char const *argv[])
{ 
    Solution so;
    cout << so.strToInt("   -42") << endl;
    

    
    return 0;
}