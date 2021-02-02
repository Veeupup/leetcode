#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (char ch : p)
            need[ch]++;

        vector<int> res;
        int left = 0, right = 0;
        int valid = 0;
        while (right < s.size()) {
            char ch = s[right];
            ++right;
            if (need.count(ch)) {
                window[ch]++;
                if (window[ch] == need[ch])
                    ++valid;
            }

            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    res.emplace_back(left);
                }
                char ch = s[left];
                ++left;
                if (need.count(ch)) {
                    if (window[ch] == need[ch])
                        --valid;
                    window[ch]--;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    string s = "cbaebabacd", p = "abc";
    auto res = so.findAnagrams(s, p);
    for (auto x : res) {
        cout << x << ", ";
    }


    return 0;
}