# Problem

[1003. 检查替换后的词是否有效](https://leetcode-cn.com/problems/check-if-word-is-valid-after-substitutions/)

# Solution

## 分析和思路

使用栈进行匹配，采用 `vector` 来模拟栈，可以方便的取出最顶部的两个元素的值。

## code

1. 字符串查找替换

```c++
class Solution {
public:
    bool isValid(string s) {
        string s1 = s;
        int beginPos = s.find("abc");
        while (beginPos != string::npos)
        {
            s.erase(beginPos, 3);
            beginPos = s.find("abc");
        }
        return s == "abc" || s == "";
    }
};
```

2. 栈

```c++
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 3 != 0)
            return false;
        bool judge=true;
        vector<char> sta;
        sta.emplace_back('#');
        sta.emplace_back('#');
        int len;
        for (int i = 0, size = s.size(); i < size; i++)
        {
            len = sta.size();
            if (s[i] != 'c')
                sta.emplace_back(s[i]);
            else {
                if (sta[len-1] == 'b' && sta[len-2] == 'a') {
                    sta.pop_back();
                    sta.pop_back();
                }else {
                    judge = false;
                    break;
                }
            }
        }
        if (judge && sta.size() == 2) 
            return true;
        return false;
    }
};
```

