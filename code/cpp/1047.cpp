#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        for (char ch : S) {
            if (ans.empty() || ans.back() != ch)
                ans.push_back(ch);
            else
                ans.pop_back();
        }
        return ans;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}