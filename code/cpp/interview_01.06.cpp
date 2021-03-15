#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressString(string S) {
        int n = S.size();
        string compress;
        int i = 0;
        while (i < n) {
            int cnt = 1;
            char ch = S[i];
            while (i + 1 < n && S[i + 1] == S[i]) {
                ++i;
                ++cnt;
            }
            compress += ch + to_string(cnt);
            ++i;
        }
        return n <= compress.size() ? S : compress;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}