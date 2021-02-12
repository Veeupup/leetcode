#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> imap;
        for (auto& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            imap[tmp].emplace_back(str);
        }
        vector<vector<string>> res;
        for (auto item : imap) {
            res.emplace_back(item.second);
        }
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}