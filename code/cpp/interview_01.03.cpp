#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        string str;
        for (int i = 0; i < length; i++) {
            if (S[i] == ' ')
                str += "%20";
            else
                str += S[i];
        }
        return str;
    }
};

int main(int argc, char const* argv []) {

    string S = "Mr John Smith    ";
    Solution so;
    cout << so.replaceSpaces(S, 13) << endl;


    return 0;
}