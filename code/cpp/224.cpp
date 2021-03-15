#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 带有括号的优先级
     *  两个栈
     *
     * @param  {string} s :
     * @return {int}      :
     */
    stack<int> nums;
    stack<char> ops;
    unordered_map<char, int> priority{
        {'(', -1}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
    };

    void replace(string& s) {
        int pos = s.find("(-");
        while (pos != string::npos) {
            s.replace(pos, 2, "(0-");
        }
    }

    int calculate(string s) {
        s = "0" + s;
        replace(s);
        for (int i = 0, size = s.size(); i < size; i++) {
            char ch = s[i];
            if (ch == ' ')
                continue;
            if (ch == '(')
                ops.push(ch);
            else if (ch == ')') {   // 计算直到遇到左边的括号
                while (!ops.empty()) {
                    char op = ops.top();
                    if (op != '(') {
                        nums.push(cal());
                        ops.pop();
                    }
                    else {
                        ops.pop();
                        break;
                    }
                }
            }
            else {
                if (isdigit(ch)) {  // 如果有连续的数字，需要将其计算之后放入栈中
                    int num = 0;
                    while (isdigit(s[i])) {
                        num = num * 10 + (s[i++] - '0');
                    }
                    --i;
                    nums.push(num);
                }
                else {
                    // 当符号栈顶的符号优先级大于当前的优先级的时候
                    while (!ops.empty() && priority[ops.top()] >= priority[ch]) {
                        nums.push(cal());
                        ops.pop();
                    }
                    ops.push(ch);   //
                }
            }
        }
        while (!ops.empty()) {
            nums.push(cal());
            ops.pop();
        }

        return nums.top();
    }

    int cal() {
        int num1 = nums.top();
        nums.pop();
        int num2 = nums.top();
        nums.pop();
        char op = ops.top();
        if (op == '+') {
            return num1 + num2;
        }
        else if (op == '-') {
            return num2 - num1;
        }
        else if (op == '*') {
            return num1 * num2;
        }
        else if (op == '/') {
            return num2 / num1;
        }
        return -1;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.calculate("1 + 10 * 2 - 14 / (8-2)") << endl;
    cout << so.calculate(" 2-1 + 2 ") << endl;
    cout << so.calculate(" 2-(1 + 2) ") << endl;
    cout << so.calculate("(1+(4+5+2)-3)+(6+8)") << endl;

    return 0;
}