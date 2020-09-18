[TOC]

# Problem

给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

 

```
示例:

输入: [1,2,3,4]
输出: [24,12,8,6]


提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
```



# Solution

## 思路和分析

如果使用除法，那么本题会很简单，本题的要求是不使用除法，而且在 `O(n)` 时间复杂度内解决这个问题。

但是这个思路在遇到 0 的时候就失效了。

思路1，

使用两个数组 L、R，其中 `L[i],R[i]` 分别代表下标 `i` 处左边所有元素的乘积和右边所有元素的乘积。



思路2，

尽管上面的方法已经能够很好的解决这个问题，但是空间复杂度并不为常数。

由于输出数组不算在空间复杂度内，那么我们可以将 L 或 R 数组用输出数组来计算。先把输出数组当作 L 数组来计算，然后再动态构造 R 数组得到结果。让我们来看看基于这个思想的算法。

算法

初始化 answer 数组，对于给定索引 i，answer[i] 代表的是 i 左侧所有数字的乘积。
构造方式与之前相同，只是我们试图节省空间，先把 answer 作为方法一的 L 数组。
这种方法的唯一变化就是我们没有构造 R 数组。而是用一个遍历来跟踪右边元素的乘积。并更新数组 `answer[i]=answer[i]*Ranswer[i]=answer[i]∗R`。然后 R 更新为 `R=R*nums[i]R=R∗nums[i]`，其中变量 R 表示的就是索引右侧数字的乘积。











## C++

思路1，

```c++
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();

        vector<int> output(length), L(length, 0), R(length, 0);

        // 计算左边的数字乘积
        L[0] = 1;
        for (int i = 1; i < length; i++)
        {
            L[i] = L[i-1] * nums[i-1];
        }

        // 计算右边的数字乘积
        R[length-1] = 1;
        for (int i = length-2; i >= 0; i--)
        {
            R[i] = R[i+1] * nums[i+1];
        }
        
        for (int i = 0; i < length; i++)
        {
            output[i] = L[i] * R[i];
        }
        
        return output;
    }
};
```

思路2，

```c++
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();

        vector<int> output(length);

        // 计算左边的数字乘积
        output[0] = 1;
        for (int i = 1; i < length; i++)
        {
            output[i] = output[i-1] * nums[i-1];
        }

        // 最开始最右边应该为 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--)
        {
            output[i] = output[i] * R;
            R = nums[i] * R;
        }
        
        return output;
    }
};
```







