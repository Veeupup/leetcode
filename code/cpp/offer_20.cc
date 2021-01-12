#include <bits/stdc++.h>
using namespace std;

// 找到数字的模式：
// 1. 可能带有正负号
// 2. 可能有字母 e =》前后必须也是数字
// 3. 数字可能包含小数点
// 解决方法：
// 1标志符号，是否是数字
// 2标志符号 是否出现过小数点 
// 3是否出现 e ，出现 e 则重新开始判断是否是数字
class Solution {
public:
    bool isNumber(string s) {
        if (s.size() == 0)
            return false;
        int index = 0;
        // trim before
        while (s[index] == ' ')
            ++index;
        
        // 小数点前是否包含数字
        bool numeric = scanSignedInteger(s, index); 
        if (s[index] == '.') {
            index++;
            // 判断小数点前与小数点后只要有一个是数字即可
            numeric = scanInteger(s, index) || numeric; 
        }
        
        if (s[index] == 'e' || s[index] == 'E') {
            index++;
            // e 前面的是数字，且之后的是带符号的数字
            numeric = numeric && scanSignedInteger(s, index);  
        }
        
        while (s[index] == ' ')
            index++;
        
        return numeric && index == s.size();
    }

    bool scanSignedInteger(string s, int& index) {
        if (s[index] == '+' || s[index] == '-')
            index++;
        return scanInteger(s, index);
    }
    
    bool scanInteger(string s, int& index) {
        int before = index;
        while (index < s.size() && s[index] >= '0' && s[index] <= '9')
            index++;
        return index > before;
    }
};

int main(int argc, char** argv) {
    char* str = argv[1];
    Solution so;
    cout << so.isNumber(str) << endl;
    return 0;
}
