#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 匹配的括号
     * @param  {string} s :
     * @return {bool}     :
     */
    bool isValid(string s) {
        stack<char> ista;
        auto isMatch = [&](char ch)->bool {
            if (ch == '(' || ch == '{' || ch == '[')
                return false;
            if (ch == ')' && ista.top() == '(')
                return true;
            if (ch == '}' && ista.top() == '{')
                return true;
            if (ch == ']' && ista.top() == '[')
                return true;
            return false;
        };
        for (char ch : s) {
            if (ista.empty() || !isMatch(ch))
                ista.push(ch);
            else
                ista.pop();
        }
        return ista.empty();
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.isValid("(){}[]") << endl;
    cout << so.isValid("(){][]") << endl;
    cout << so.isValid("(]") << endl;


    return 0;
}