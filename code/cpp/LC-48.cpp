#include <bits/stdc++.h>
using namespace std;

/**
 * 计算出最长不重复的子串，方法：
 * 首先就是暴力搜索，从每个位置开始搜索，时间复杂度太高
 * 
 * 使用双指针，使用 hashset 保存字符是否出现
 * 
 * 
 *  
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        unordered_map<char, int> imap;
        int start = -1; // 代表开始的位置的前一个
        for (int i = 0, len = s.size(); i < len; i++)
        {
            char ch = s[i];
            if (imap.find(ch) != imap.end())
                start = max(start, imap[ch]); // 更新左指针，为第一个重复的数字的位置
            imap[ch] = i;
            res = max(res, i - start);
        }
        return res;
    }
};

int main()
{
    Solution so;
    string str = "abcabcbb";
    cout << so.lengthOfLongestSubstring(str) << endl;

    return 0;
}