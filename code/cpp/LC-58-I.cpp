#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 反转字符串，单词间顺便反，单词内不反
     * 使用双指针，从末尾向前找
     * @param  {string} s : 
     * @return {string}   : 
     */
    string reverseWords(string s) {
        // trim
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        int i = s.size() - 1, j = i;
        string res;
        while (i >= 0) {
            while (i >= 0 && s[i] != ' ') i--;
            res.append(s.substr(i+1, j-i) + " ");
            while (i >= 0 && s[i] == ' ') i--;  // 跳过空格
            j = i;
        }
        res.erase(res.find_last_not_of(" ") + 1);
        return res;
    }
};

int main()
{ 
    Solution so;
    string s = "      the sky is blue    ";
    cout << "|" <<so.reverseWords(s) << "|" << endl;
    

    
    return 0;
}