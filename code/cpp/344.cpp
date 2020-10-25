#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int i = 0;
        while (i < len)
        {
            int start = i;
            while (i < len && s[i] != ' ')
                i++;
            
            int left = start, right = i - 1;
            while (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            
            while (i < len && s[i] == ' ') 
                i++;
        }
        return s;
    }
};

int main() {

    Solution *so = new Solution;
    string str = "Let's take LeetCode contest";

    cout << so -> reverseWords(str) << endl;

    return 0;
}