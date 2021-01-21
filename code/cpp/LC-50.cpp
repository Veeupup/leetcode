#include <bits/stdc++.h>
using namespace std;

/**
 *  找到第一个只出现一次的字符，那么必然需要遍历整个字符串
 * 对于每个字符，保存出现的位置，因为之后可能是需要返回的值，如果出现了重复的值，那么就增加这个字符的值
 * map 本身是有序的，利用 map 的特性，取出头节点即可
 * 
*/

class Solution
{
public:
    /**
     * 寻找字符串中第一个不重复的字符
     * @param  {string} s : 输入字符串
     * @return {char}     : 第一个不重复的字符
     */
    char firstUniqChar(string s)
    {
        map<char, bool> imap;
        for (char ch : s)
            imap[ch] = imap.find(ch) == imap.end();
        for (char ch : s)
            if (imap[ch])
                return ch;
        return ' ';
    }
};

int main()
{
    Solution so;
    string str = "abaccdeff";
    cout << so.firstUniqChar(str) << endl;

    return 0;
}