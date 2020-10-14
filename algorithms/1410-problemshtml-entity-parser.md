[TOC]

# Problem

[HTML 实体解析器](https://leetcode-cn.com/problems/html-entity-parser/)

# Solution

## 分析和思路

使用库函数 `find`，`replace`，寻找每个被 `&` 和 `;` 包围起来的字符串，查看是否是需要替换的字符串，如果是的话，替换这个字符串为对应的字符，由于该字符长度都为 1，所以需要在下一次开始寻找的位置 加 1。

## code

```c++

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
```

