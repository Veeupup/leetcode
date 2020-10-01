[TOC]

# Problem

给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

```
示例 1 :

输入: 2736
输出: 7236
解释: 交换数字2和数字7。
示例 2 :

输入: 9973
输出: 9973
解释: 不需要交换。
注意:

给定数字的范围是 [0, 10^8]
```



# Solution

## 分析和思路

给定一个数字，交换数字中的两位，让整个数字最大，这个时候需要让高位的数字尽可能大，也就是说在所有数字中找到最大的数字和最高位交换，然后输出。

这个题是一个 DP 问题，因为具有最优子结构的性质，当输入的数字有 `m` 位时候，和 `m-1` d的问题答案有相似的性质。

1. `maximumSwap(m) = maximumSwap(m-1)`，当第 `m` 位比前 `m-1` 位中最大的还要大的时候
2. `maxumumSwap(m) = swap(arr[m], best(arr(m-1)))`，当第 m 位的数字比之前数字中最大的要更小的时候，交换这两个数字即可。

在这个过程中，不需要真正的计算出每一步的值，只需要两个指针指向这两个位置即可。



思路2：

先由大到小排序，时间复杂度为O（nlogn），对比排序前后字符串，找出第一个不一样的，这两个就是要交换的数，然后从排序前的那个开始往后面找出与排序后的数一样的，交换即可



## 新的学习点

* `to_string`， 可以把整数和浮点数转换成字符串，https://zh.cppreference.com/w/cpp/string/basic_string/to_string
* `stoi`，字符串转为数字



## code

```c++
class Solution {
public:
    int maximumSwap(int num) {
        if (num <= 9) 
            return num;
        string s = to_string(num);
        string temp(s);

        // lambda 将数组排序
        sort(temp.begin(), temp.end(), [](char a, char b) {return a > b;});

        int pos = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != temp[i]) {
                pos = i;
                break;
            }
        }
        if (pos == -1)
            return num;
        // 从后往前找到要交换的位置
        for (int i = s.size() - 1; i >= pos + 1; i--)
        {
            if(s[i] == temp[pos]) {
                swap(s[i], s[pos]);
                break;
            }
        }
    
        return stoi(s);
    }
};
```

