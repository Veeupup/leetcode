[TOC]

# Problem

[1124. 表现良好的最长时间段](https://leetcode-cn.com/problems/longest-well-performing-interval/)

# Solution

## 分析和思路

1, 单调栈，

[这个思路](https://leetcode-cn.com/problems/longest-well-performing-interval/solution/can-kao-liao-ji-ge-da-shen-de-ti-jie-zhi-hou-zong-/)分析的非常好，要多理解，自己把每个过程都要想清楚



## code

```c++
class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        vector<int> arr;
        for (auto hour : hours) {
            if (hour > 8)
                arr.emplace_back(1);
            else
                arr.emplace_back(-1);
        }

        // 计算前缀和数组
        vector<int> prefixSum;
        int currSum = 0;
        for (auto val : arr)
        {
            prefixSum.emplace_back(currSum);
            currSum += val;
        }
        prefixSum.emplace_back(currSum);

        // 保存一个单调递减的元素的下标和
        stack<int> staPos;
        for (int i = 0, size = prefixSum.size(); i < size; i++)
        {
            if (staPos.size() == 0 || prefixSum[staPos.top()] > prefixSum[i])
                staPos.push(i);
        }

        // 逆向遍历前缀和数组，找到最长的
        int res = 0;
        for (int j = prefixSum.size() - 1; j >= 0; j--)
        {
            while (staPos.size() != 0 && prefixSum[j] > prefixSum[staPos.top()])
            {
                res = max(res, j - staPos.top());
                staPos.pop();
            }
        }

        return res;
    }
};
```

