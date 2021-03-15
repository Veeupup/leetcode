#include <bits/stdc++.h>
using namespace std;

// https://leetcode-cn.com/problems/check-permutation-lcci/
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        unordered_map<char, int> windows;
        for (char ch : s1) {
            if (windows.find(ch) == windows.end()) {
                windows[ch] = 1;
            }else {
                ++windows[ch];
            }
        }
        for (char ch : s2) {
            if (windows.find(ch) == windows.end())
                return false;   // s2 出现了 s1 没有的字符
            if(--windows[ch] == 0) {
                windows.erase(ch);
            }
        }
        return windows.size() == 0;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}