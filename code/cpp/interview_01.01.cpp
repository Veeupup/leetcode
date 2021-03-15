#include <bits/stdc++.h>
using namespace std;

// https://leetcode-cn.com/problems/is-unique-lcci/
class Solution {
public:
    bool isUnique(string astr) {
        int hashtable[256] = { 0 };
        for (char ch : astr) {
            if (hashtable[ch] == 1) {
                return false;
            }
            else {
                hashtable[ch] = 1;
            }
        }
        return true;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}