#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "")
            return true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (!isalnum(s[i])) {
                i++;
            }
            while (!isalnum(s[j])) {
                j--;
            }
            if (i >= j)
                break;
            char ch1 = tolower(s[i]);
            char ch2 = tolower(s[j]);
            if (ch1 == ch2) {
                i++;
                j--;
                continue;
            }

            else
                return false;

        }
        return true;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.isPalindrome("A man, a plan, a canal: Panama") << endl;


    return 0;
}