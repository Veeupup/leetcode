#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 3 != 0)
            return false;
        bool judge=true;
        vector<char> sta;
        sta.emplace_back('#');
        sta.emplace_back('#');
        int len;
        for (int i = 0, size = s.size(); i < size; i++)
        {
            len = sta.size();
            if (s[i] != 'c')
                sta.emplace_back(s[i]);
            else {
                if (sta[len-1] == 'b' && sta[len-2] == 'a') {
                    sta.pop_back();
                    sta.pop_back();
                }else {
                    judge = false;
                    break;
                }
            }
        }
        if (judge && sta.size() == 2) 
            return true;
        return false;
    }
};

int main() {
    Solution *so = new Solution();
    string str;

    str = "aabcbc";
    cout << so->isValid(str) << endl;

    return 0;
}
