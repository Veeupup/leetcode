#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, right = 0;
        int res = -1;
        while (right < s.size()) {
            char ch = s[right];
            while (window.count(ch)) {
                window.erase(s[left]);
                ++left;
            }
            window.insert(ch);
            ++right;
            res = max(res, right - left);
        }
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}