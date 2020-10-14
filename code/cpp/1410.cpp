#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    unordered_map<string, string> strChangMap = {{"&quot;", "\""},{"&apos;", "'"},{"&amp;", "&"},{"&gt;", ">"},{"&lt;", "<"},{"&frasl;", "/"}};
    string entityParser(string text) {
        string resText = text;
        int beginPos = resText.find('&');
        int endPos = resText.find(';');
        while (endPos != -1 && beginPos != -1)
        {
            string strTmp = resText.substr(beginPos, endPos - beginPos + 1);
            if (strChangMap.find(strTmp) != strChangMap.end()) {
                resText.replace(resText.begin() + beginPos, resText.begin() + endPos + 1, strChangMap[strTmp]);
            }
            beginPos = resText.find('&', beginPos + 1);
            endPos = resText.find(';', beginPos + 1);
        }
        return resText;
    }
};

int main() {
    Solution *so = new Solution();
    string str;

    // str = "&amp; is an HTML entity but &ambassador; is not.";
    // cout << so->entityParser(str) << endl;  

    // str = "and I quote: &quot;...&quot;";
    // cout << so->entityParser(str) << endl;  

    // str = "Stay home! Practice on Leetcode :)";
    // cout << so->entityParser(str) << endl;  

    // str = "&amp;amp;";
    // cout << so->entityParser(str) << endl;  

    str = "&amp;gt;";
    cout << so->entityParser(str) << endl;  

    return 0;
}
