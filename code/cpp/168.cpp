#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 这个题和普通的进制转换不同的一点在于 余数是 1~26，而正常的 26 进制应该是 0~25
    // 不应该含有进制本身 26，所以需要将 1~26 =》0~25，每次都需要将 num--
    // 但是进制仍然是 26
    string convertToTitle(int columnNumber) {
        string res = "";
        while (columnNumber) {
            columnNumber--;
            int remain = columnNumber % 26;
            res.push_back(remain + 'A');
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}