#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 奇数字符的个数最多只有一个
    bool canPermutePalindrome(string s) {
        unordered_set<char> bags;
        for (char ch : s) {
            if (bags.find(ch) == bags.end())
                bags.insert(ch);
            else 
                bags.erase(ch);
        }
        return bags.size() <= 1;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}