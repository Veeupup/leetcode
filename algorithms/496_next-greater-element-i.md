[TOC]

# Problem

给定两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

```

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
    
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。


提示：

nums1和nums2中所有元素是唯一的。
nums1和nums2 的数组大小都不超过1000。

```

# Solution

### 分析和思路

**方法 1：**

**暴力法：**

遍历 nums1 中的每个元素，然后在 nums2 中从前往后去找到这个元素，当找到这个元素之后，从当前位置的下一个位置开始搜索，直到找到第一个比这个元素大的元素，或者直到数组的末尾。

时间复杂度 O（n<sup>2</sup>），空间复杂度O（n）。



方法2：

**单调栈：**

首先忽略 nums1，先求出 nums2 中的每一个元素的下一个最大元素，然后将这个结果放入 map 中，然后遍历 nums1 找到每一个对应的结果。如果要求 nums2 中每个元素的下一个更大的元素，可以用到单调栈。

单调栈的求法，首先 将第一个元素入栈，然后遍历到第二个元素，如果这个元素比栈顶的元素大，说明这个元素就是比栈顶元素更大的下一个元素，此时将栈顶元素出栈，并且在 map 中保存这个关系；如果遍历道的这个元素小于等于栈顶的元素，那么将这个元素放入栈中。如果遍历结束，栈中还有元素，那么说明这些元素找不到下一个比这个元素更大的元素，将其无更大元素的信息放入 map 中，例如使用 -1 来保存这个结果。





## code

单调栈：

```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextBig;
        stack<int> sta;
        // 构建单调栈
        for (auto val : nums2)
        {
            while(!sta.empty() && val > sta.top()) {
                nextBig[sta.top()] = val;
                sta.pop();
            }
            sta.emplace(val);
        }
        // 如果栈中还有元素,那么说明没有下一个更大的元素
        while (!sta.empty())
        {
            nextBig[sta.top()] = -1;
            sta.pop();
        }

        vector<int> result;
        for (auto val : nums1)
            result.emplace_back(nextBig[val]);
        
        return result;
    }
};
```









暴力法

```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int start;
        for (auto x : nums1)
        {
            for (int i = 0; i < nums2.size(); i++)
            {
                if (x == nums2[i]) {
                    bool hasFind = false;
                    start = i + 1;
                    while (start < nums2.size())
                    {
                        if (nums2[start] > x) {
                            result.push_back(nums2[start]);
                            hasFind = true;
                            break;
                        }
                        start++;
                    }
                    if (!hasFind) {
                        result.push_back(-1);
                    }
                    break;
                }
            }
            
        }
        return result;
    }
};
```

