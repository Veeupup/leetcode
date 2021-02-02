#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char ch : t)
            need[ch]++;
        
        int left = 0, right = 0;
        int valid = 0, start = 0, len = INT_MAX;
        while (right < s.size()) {
            char ch = s[right];
            ++right;    // 移动右窗口
            if (need.count(ch)) {   // 是需要的元素
                ++window[ch];   // 增加窗口内的值
                if (window[ch] == need[ch])
                    ++valid;
            }

            // 收缩左窗口
            while (valid == need.size()) {
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }
                char ch = s[left];
                ++left;
                if (need.count(ch)) {
                    if (window[ch] == need[ch])
                        --valid;
                    --window[ch];
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main(int argc, char const *argv[])
{ 

    Solution so;
    string s = "ADOBECODEBANC", t = "ABC";
    cout << so.minWindow(s, t) << endl;

    
    return 0;
}