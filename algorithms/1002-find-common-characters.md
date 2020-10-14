[TOC]

# Problem

给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

 

```
示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：["cool","lock","cook"]
输出：["c","o"]


提示：

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母
```



# solution

## 分析和思路

需要保存在所有字符串中，每个字符出现的最少次数，这是这道题需要求出来的。

所以使用一个 minFreq 来保存每个字符串中每个字符出现的最少次数，然后遍历所有字符串 s ，使用 freq 统计 s 中每个字符出现的次数。统计完成之后，再将每个 minFreq[c] 更新为其本身与 freq[c] 的较小值，这样当遍历完所有字符串之后，minFreq[c] 就保存了 c 在所有字符串中出现的最小次数。



## code

```c++
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> minFreq(26, INT_MAX);
        vector<int> freq(26);
        for (const string& word : A)
        {
            fill(freq.begin(), freq.end(), 0);
            for (char ch : word) {
                ++freq[ch-'a'];
            }
            for (int i = 0; i < 26; i++)
            {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < minFreq[i]; j++)
            {
                ans.emplace_back(1, i +'a');
            }
        }
        
        return ans;
    }
};
```

