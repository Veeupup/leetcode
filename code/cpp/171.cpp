#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (char ch : columnTitle) {
            int num = ch - 'A' + 1;
            res = res * 26 + num;
        }
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}