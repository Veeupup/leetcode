[TOC]

# Problem

给定两个整数数组，请交换一对数值（每个数组中取一个数值），使得两个数组所有元素的和相等。

返回一个数组，第一个元素是第一个数组中要交换的元素，第二个元素是第二个数组中要交换的元素。若有多个答案，返回任意一个均可。若无满足条件的数值，返回空数组。

```
示例:

输入: array1 = [4, 1, 2, 1, 1, 2], array2 = [3, 6, 3, 3]
输出: [1, 3]
示例:

输入: array1 = [1, 2, 3], array2 = [4, 5, 6]
输出: []
提示：

1 <= array1.length, array2.length <= 100000
```



# Solution

## 分析和思路

思路1，

首先计算出 sumA， sumB，然后计算出 `dis = sumA - sumB`，二者的相差的值为 dis，如果交换 数组 A 中的 a 和 数组 B 中的 b，二者的差距将变为 2 * (a - b)，因为一个和增加了 `a-b`，另外一个的和减少了 `a - b`，所以需要在 A， B 中找到两个元素的差值为 `dis / 2 = (a - b)`。

其中，如果 sumA > sumB，那么需要在 A 数组中找到较小的值和 B 数组中的值交换，否则在 A 中找到 较大的值。

* 暴力遍历，可以操作，在最后的非常大的数据量的时候直接超时

> 超时

* 在暴力的基础上进行优化

  * 如果有很多相同的元素，那么可以直接跳过这些元素的筛查，用哈希表记录完成

  > 执行用时：320 ms, 在所有 C++ 提交中击败了5.27%的用户
  >
  > 内存消耗：33.5 MB, 在所有 C++ 提交中击败了5.24%的用户

* 继续优化

  * 如果有了哈希表，那么直接先把 A， B 中所有元素放入两个个 set ，然后遍历 A 中所有元素，然后看 B 中是否存在对应的即可！

  > 执行用时：172 ms, 在所有 C++ 提交中击败了29.38%的用户
  >
  > 内存消耗：32.2 MB, 在所有 C++ 提交中击败了46.85%的用户

* 继续优化

不用 `vector` 返回，使用 set 的 find 函数来提高程序效率。

> 执行用时：144 ms, 在所有 C++ 提交中击败了46.89%的用户
>
> 内存消耗：32.1 MB, 在所有 C++ 提交中击败了74.13%的用户



## code

1. 暴力遍历

```c++
class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        vector<int> result;
        int sumA = 0, sumB = 0;
        for (int i : array1) 
            sumA += i;
        for (int i : array2) 
            sumB += i;
        int dis = sumA - sumB;
        if (dis % 2 != 0)
            return result;
        dis /= 2;   // 如果 sumA > sumB,那么 dis > 0,需要在 A 中找到较大的送给 B
        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());
        for (int a : array1)
        {
            for (int b : array2) {
                // a 才行，所以是 
                if ( a - b == dis ) {
                    result.push_back(a);
                    result.push_back(b);
                    return result;
                }
            }
        }
        return result;
    }
};
```

2. 从暴力遍历的基础上优化，使用 哈希表

```c++
class Solution
{
public:
    vector<int> findSwapValues(vector<int> &array1, vector<int> &array2)
    {
        vector<int> result;
        int sumA = 0, sumB = 0;
        for (int i : array1)
            sumA += i;
        for (int i : array2)
            sumB += i;
        int dis = sumA - sumB;
        if (dis % 2 != 0)
            return result;
        dis /= 2; // 如果 sumA > sumB,那么 dis > 0,需要在 A 中找到较大的送给 B
        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());
        set<int> tableA;
        for (int a : array1)
        {
            if (!tableA.count(a))
            {
                set<int> tableB;
                for (int b : array2)
                {
                    if (!tableB.count(b))
                    {
                        if (a - b == dis)
                        {
                            result.push_back(a);
                            result.push_back(b);
                            return result;
                        }
                        tableB.insert(b);
                    }
                }
                tableA.insert(a);
            }
        }
        return result;
    }
};
```

3. 采用哈希表优化查找算法

```c++
class Solution
{
public:
    vector<int> findSwapValues(vector<int> &array1, vector<int> &array2)
    {
        set<int>  tableB;
        int sumA = 0, sumB = 0;
        for (int i : array1) {
            sumA += i;
        }
        for (int i : array2) {
            sumB += i;
            tableB.insert(i);
        }  
        int dis = sumA - sumB;
        if (dis % 2 != 0)
            return {};
        dis /= 2; // 如果 sumA > sumB,那么 dis > 0,需要在 A 中找到较大的送给 B
        for (int a : array1)
        {
            // 计算出 需要的 b 的值, a - b = dis, b = a - dis
            if (tableB.find(a - dis) != tableB.end()) {
                return {a, a - dis};
            }
        }
        return {};
    }
};
```

