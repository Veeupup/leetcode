#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;
        int len = haystack.size();
        int len2 = needle.size();
        for (int i = 0; i < len - len2 + 1; i++) {
            if (haystack[i] == needle[0]) {
                int j = 1;
                for (; j < len2; j++) {
                    if (haystack[i + j] != needle[j])
                        break;
                }
                if (j == len2)
                    return i;
            }
        }
        return -1;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.strStr("hello", "ll") << endl;
    cout << so.strStr("aaaaa", "bba") << endl;

    return 0;
}