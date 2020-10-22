# Problem

[763. 划分字母区间](https://leetcode-cn.com/problems/partition-labels/)

# Solution

## 思路1，贪心

首先一次遍历，找到每个字母出现的最后的位置，使用 `last['x' - 'a']` 来保存当前字母的最后的位置。

然后从前往后，一步步扩大当前子序列的长度，这个子序列有一个性质，那就是当前子序列的所有元素的最后一个位置一定小于 `last[key]`，key 是当前这个子序列中的 `last` 值最大的元素。

```c++

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26] = {-1};
        vector<int> ans;
        int len = S.size();
        for (int i = 0; i < len; ++i) {
            if (i > last[S[i] - 'a']) {
                last[S[i] - 'a'] = i; 
            }
        }
        int start = 0, end = 0, lastPos = 0;
        // 1. 采用 while
        // while (start < len)
        // {
        //     lastPos = last[S[start] - 'a'];
        //     while (end < lastPos)
        //     {
        //         if (last[S[end] - 'a'] > lastPos) {   // 当前元素的最后位置在更后的位置
        //             lastPos = last[S[end] - 'a'];
        //         }
        //         end++;
        //     }
        //     ans.push_back(end - start + 1);
        //     start = ++end;
        // }

        // 2. 采用 for 循环写
        for (int i = 0; i < len; ++i) {
            end = max(last[S[i] - 'a'], end);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return ans;
    }
};

```

