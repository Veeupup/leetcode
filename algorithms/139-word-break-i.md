

[139. 单词拆分](https://leetcode-cn.com/problems/word-break/)

## 思路，

动态规划

思路和算法

我们定义 `dp[i]`  表示字符串s前i个字符组成的字符串 `s[0..i-1]`  是否能被空格拆分成若千个字典中出现的单词。从前往后计算考虑转移方程，每次转移的时候我们需要枚举包含位置 `i - 1` 的最后一个单词，它是否出现在字典中以及除去这部分的字符串是否合法即可。

公式化来说，我们需要枚举`s[0..i-1]` 中的分割点 `j` ,看`s[0..i-1]` 组成的字符串(默认j=0时 S<sub>1</sub>空串)和 `s[j..i- 1]` 组成的字符串 S<sub>2</sub>是都合法，如果两个字符串均合法，那么按照定义 S<sub>1</sub>和 S<sub>2</sub>拼接成的字符串也同样合法。由于计算到 `dp[i]`  我们已经计算出了`dp[0..i- 1] `的值，因此字符串 S<sub>1</sub>是否合法可以直接由`dp[j] `得知，剩下的我们只需要看 S<sub>2</sub>是否合法即可，因此我们可以得出如下转移方程:

 `dp[i]  =  dp[i] && check(s[j..i - 1]) `

其中`check(s[j..i- 1]) `示子串`s[j..i - 1]`是否出现在字典中。

对于检查一个字符串是否出现在给定的字符串列表里一般可以考虑哈希表来快速判断，同时也可以做一些简单的剪枝，枚举分割点的时候倒着枚举,如果分割点j到i的长度已经大于字典列表里最长的单词的长度,那么就结束枚举，但是需要注意的是下面的代码给出的是不带剪枝的写法。




```c++
cla `s`  Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (auto str : wordDict) {
            wordSet.insert(str);
        }

        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
             `dp[i]`  = false;
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                     `dp[i]`  = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
```





[140. 单词拆分 II](https://leetcode-cn.com/problems/word-break-ii/)

动态规划，其实就是把这个题变成深度搜索，建立一颗深度搜索的多叉树，然后递归回溯。

官方题解：

对于字符串  `s` ，如果某个前缀是单词列表中的单词，则拆分出该单词，然后对  `s`  的剩余部分继续拆分。如果可以将整个字符串  `s`  拆分成单词列表中的单词，则得到一个句子。在对  `s`  的剩余部分拆分得到一个句子之后，将拆分出的第一个单词（即  `s`  的前缀）添加到句子的头部，即可得到一个完整的句子。上述过程可以通过回溯实现。

假设字符串  `s`  的长度为 nn，回溯的时间复杂度在最坏情况下高达 O(n<sup>n</sup>)。时间复杂度高的原因是存在大量重复计算，可以通过记忆化的方式降低时间复杂度。

具体做法是，使用哈希表存储字符串  `s`  的每个下标和从该下标开始的部分可以组成的句子列表，在回溯过程中如果遇到已经访问过的下标，则可以直接从哈希表得到结果，而不需要重复计算。如果到某个下标发现无法匹配，则哈希表中该下标对应的是空列表，因此可以对不能拆分的情况进行剪枝优化。

还有一个可优化之处为使用哈希集合存储单词列表中的单词，这样在判断一个字符串是否是单词列表中的单词时只需要判断该字符串是否在哈希集合中即可，而不再需要遍历单词列表。



也可以看看 第二个题解，回溯来求。

https://leetcode-cn.com/problems/word-break-ii/solution/dong-tai-gui-hua-hui-su-qiu-jie-ju-ti-zhi-python-d/



如果对于函数的递归迭代过程不清楚，可以使用 gdb 单步调试来看函数的调用过程。

```c++
cla `s`  Solution {
private:
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordSet;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto word : wordDict) {
            wordSet.insert(word);
        }
        backtrack(s, 0);
        return ans[0];
    }

    void backtrack(string s, int index) {
        if (!ans.count(index)) {    // 如果没有进行计算过
            if (index == s.size()) {
                ans[index] = {""};
                return;
            }
            ans[index] = {};    // 初始化当前返回值
            for (int i = index + 1; i < s.size(); ++i) {    // 从当前下标，找到前缀符合的第一个单词
                string word = s.substr(index, i - index);   // 从当前下标一直找，直到找到第一个符合的单词
                if (wordSet.count(word)) {
                    backtrack(s, i);    // 从当前找到的单词的下一个开始找
                    for (const string& succ: ans[i]) {
                        ans[index].push_back(succ.empty() ? word : word + " " + succ);	// 当前就记录下所有的可能，直接记录可能的字符串
                    }
                }
            }
        }
    }
};
```

