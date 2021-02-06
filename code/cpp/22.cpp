#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 括号生成
     *  生成有效的括号对数
     *
     * 左括号的右边一定有一个对应的右括号
     * 确定好左括号的位置，那么右括号就确定了
     * n = 3
     * _ _ _ _ _ _
     *
     * 1. 暴力法
     *  生成所有的可能括号，然后剪枝
     *  剪枝的策略，如果当前 已经有匹配的括号 = 没有元素，那么就不能直接放右边括号，只能放左括号
     *  左括号一定是随时都可以放的，但是右括号放的时候需要进行考虑，是否能够放，放了就无法匹配了
     * @param  {int} n           :
     * @return {vector<string>}  :
     */
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string str;
        // dfs(0, 2 * n, str);
        generate(0, 0, n * 2, n, str);
        return res;
    }

    void generate(int depth, int score, int n, int max, string& str) {
        if (depth == n) {
            if (score == 0)
                res.emplace_back(str);
        }
        else {
            if (score + 1 <= max)
                generate(depth + 1, score + 1, n, max, str + "(");
            if (score - 1 >= 0)
                generate(depth + 1, score - 1, n, max, str + ")");
        }

    }

    void dfs(int depth, int n, string& str) {
        if (n == depth) {
            if (isValid(str))
                res.emplace_back(str);
            return;
        }
        str.append("(");
        dfs(depth + 1, n, str);
        str.pop_back();
        if (isValid(str)) { // 当前已有的元素能够匹配，那么就不能放右括号
            return;
        }
        str.append(")");
        dfs(depth + 1, n, str);
        str.pop_back();
    }

    bool isValid(string s) {
        stack<char> ista;
        auto isMatch = [&](char ch)->bool {
            if (ch == '(')
                return false;
            if (ch == ')' && ista.top() == '(')
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
    vector<string> ans = so.generateParenthesis(3);
    for (auto str : ans)
        cout << str << endl;

    return 0;
}