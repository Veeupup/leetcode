#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Z 形变换
     *
     *
     *
     *
     * @param  {string} s    :
     * @param  {int} numRows :
     * @return {string}      :
     */
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        for (char ch : s) {
            rows[curRow] += ch;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows)
            ret += row;
        return ret;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}