# Problem

[845. 数组中的最长山脉](https://leetcode-cn.com/problems/longest-mountain-in-array/)

# Solution

## 双指针

使用双指针，一次遍历即可。

时间复杂度 `O(N)`，空间复杂度`O(1)`。

首先如果数组的长度小于 3，那么直接返回 false；

长度大于3，从头开始遍历，使用 start 保存开始上坡的位置，pos 作为游标向后遍历，top 保存山顶的位置的下标

首先找上坡，当找到上坡的顶点之后，开始找下坡，同时需要保存山顶的下标位置，当找到山底之后，计算

* 山底到山顶的长度 pos - start + 1 是否大于3
* 查看山顶的位置 top 是否大于 start，此时才有上坡
* 查看山底的位置 pos 时候大于 top，此时才会有下坡

同时如果当前是平坡，发现不变的时候，需要手动向前走一步，不然就会一直停在原地。

执行用时：40 ms, 在所有 C++ 提交中击败了88.85%的用户

内存消耗：18.4 MB, 在所有 C++ 提交中击败了25.59%的用户

```c++
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.size() < 3)
            return 0;
        int ret = 0;
        int start = 0, pos = 0, len = A.size(), top = 0;
        while (start < len)
        {
            // pos = start;
            while (pos + 1 < len && A[pos+1] > A[pos]) {  // 先找上升的阶段
                pos++;
                top = pos;  // 
            }   // 此时 pos 表示顶点的下标
            while (pos + 1 < len && A[pos+1] < A[pos]) {
                pos++;
            }   // 此时遇到第二次上坡，pos 代表最低点的位置
            if (pos - start + 1 >= 3 && top < pos && top > start)  
                ret = max(ret, pos - start + 1);
            if (pos == start)
                pos++;
            start = pos;
        }
        return ret;
    }
};
```

