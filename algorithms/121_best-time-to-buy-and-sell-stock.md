[TOC]

# Problem

#### [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

 

```

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。

```



```
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```



# Solution

## 分析与思路

本题需要求两个元素的最大差值，但是较小元素的下标也要比较大元素的下标更小。

假设数组的长度为 n（n>=0）。

### 思路1,暴力

暴力，从前往后遍历所有的元素之间的差值，求得最大的差值并保存，时间复杂度为 O(n<sup>2</sup>)。

```c++
int best = 0, len = prices.size();
for (int i = 0; i < len; i++)
{
  for (int j = i+1; j < len; j++)
  {
    int temp = prices[j] - prices[i];
    best = temp > best ? temp : best;
  }
}
return best;
```

直接超时。

### 思路2,动态规划

DP 中解决问题的思路是找到需要解决问题的最优子结构，当子结构是最优的时候，整个问题也就具有了最优解。

在本题中需要找到最优子结构，最优子问题。

从前往后遍历，每次遍历到的新的位置一定能保证新位置的下标大于之前的下标，所以只需要记录下之前的最小值，同时遍历的时候计算出遍历到的新的位置的值和之前最小值的差值即可。

## Java

```java
class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if (len <= 1)
            return 0;
        int best = 0, low = prices[0], high = prices[0];
        for (int i = 1; i < len; i++)
        {
            int temp = prices[i] - low;
            best = temp > best ? temp : best;
            low = prices[i] < low ? prices[i] : low;
        }
        return best; 
    }
}
```



## C++

```c++
int maxProfit(vector<int>& prices) {
  int len = prices.size();
  if (len <= 1)
    return 0;
  int best = 0, low = prices[0], high = prices[0];
  for (int i = 1; i < len; i++)
  {
    int temp = prices[i] - low;
    best = temp > best ? temp : best;
    low = prices[i] < low ? prices[i] : low;
  }
  return best;    
}  
```



