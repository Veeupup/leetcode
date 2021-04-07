#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        string s3 = s1;
        s3 += s1;
        return s3.find(s2) != string::npos;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}