#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char ch : s1)
            need[ch]++;

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char ch = s2[right];
            ++right;
            if (need.count(ch)) {
                ++window[ch];
                if (window[ch] == need[ch])
                    ++valid;
            }

            while (right - left >= s1.size()) {    // 当长度大于等于 s1 时
                if (valid == need.size())
                    return true;
                char ch = s2[left];
                ++left;
                if (need.count(ch)) {
                    if (need[ch] == window[ch])
                        --valid;
                    --window[ch];
                }
            }
        }
        return false;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}