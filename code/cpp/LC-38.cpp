#include <bits/stdc++.h>
using namespace std;

/**
* 全排列，递归
    参数，给出当前应该固定的位置，然后循环进行交换，直到 n == s.size()
*/

class Solution {
public:
    vector<string> res;
    set<string> words;
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
    
    void dfs(string& s, int idx) {
        if (idx == s.size() && words.find(s) == words.end()) {
            res.emplace_back(s);
            words.insert(s);
        }
        for (int i = idx; i < s.size(); i++) {
            swap(s[i], s[idx]);
            dfs(s, idx+1);
            swap(s[i], s[idx]);
        }
    }
};

int main()
{ 
    Solution so;
    auto res = so.permutation("abc");
    for(auto& s : res) {
        cout << s << endl;
    }
    return 0;
}