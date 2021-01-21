#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string tmp = s.substr(0, n);
        s.erase(0, n);
        s.append(tmp);
        return s;
    }
};

int main(int argc, char const* argv []) {
    Solution so;
    cout << so.reverseLeftWords("abcdefgh", 3) << endl;



    return 0;
}