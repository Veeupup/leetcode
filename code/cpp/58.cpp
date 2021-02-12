#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0)
            return 0;
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (cnt == 0)
                    continue;
                break;
            }
            cnt++;
        }
        return cnt;
        // s.erase(s.find_last_not_of(" ") + 1);
        // s.erase(0, s.find_first_not_of(" "));
        // auto pos = s.find_last_of(" ");
        // if (pos == string::npos)
        //     return s.size();
        // return s.size() - pos - 1;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.lengthOfLastWord("  Hello World  ") << endl;
    cout << so.lengthOfLastWord("   ") << endl;


    return 0;
}