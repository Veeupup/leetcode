[TOC]

# Problem

#### [1208. 尽可能使字符串相等](https://leetcode-cn.com/problems/get-equal-substrings-within-budget/)

给你两个长度相同的字符串，s 和 t。

将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。

用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。

如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。

如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。

 

```
示例 1：

输入：s = "abcd", t = "bcdf", cost = 3
输出：3
解释：s 中的 "abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。
```
```
示例 2：

输入：s = "abcd", t = "cdef", cost = 3
输出：1
解释：s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为 1。
```
```
示例 3：

输入：s = "abcd", t = "acde", cost = 0
输出：1
解释：你无法作出任何改动，所以最大长度为 1。
```
```
提示：

1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s 和 t 都只含小写英文字母。
```



# Solution

## 分析和思路

长度相同的字符串，定义出了两个字符串某个字符之间的距离，同时给出能够改变的最大距离。

思路1，

计算出每个字符之间的距离，用两个游标来保存前后两个指针，首先前面的指针不动，移动后面的指针，一直到 子字符串的距离 大于 maxConst（同时保存相距最大的长度），然后再移动前面的指针一位，直到满足条件之后再移动后面的指针。

如果两个指针位置相同，那么需要同时移动指针向后一位。

思路2，**滑动窗口（第一次遇到）**

上方的思路就是 滑动窗口的思路，但是代码层面还可以进行优化。



## C++

思路1，

执行用时：36 ms, 在所有 C++ 提交中击败了5.61%的用户

内存消耗：7.4 MB, 在所有 C++ 提交中击败了67.04%的用户

```c++
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int length = s.size();
        int left = 0, right = 0;    // 保存游标
        int nowCost = 0, ans = 0;    // 保存已经花费的距离

        while (right < length)
        {
            int tempDis = abs(s[right] - t[right]);
            if (nowCost + tempDis <= maxCost) {
                // 之前字符的距离 + 当前字符的距离 <= 最大花费，那么可以 right 移动一位
                nowCost += tempDis;
                right++;    // 右游标右移
                if (right - left > ans) 
                    ans = right - left;
            }else if (right > left) {
                // 加上当前字符的距离大于 maxCost，此时移动左游标
                nowCost -= abs(s[left] - t[left]);
                left++;
            }else {
                // 如果两个游标相等，那么两个游标同时向右移动
                left++;
                right++;
            }
        }
        return ans;
    }
};
```



思路2，滑动窗口（代码优化）

```c++
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int length = s.size();
        int left = 0, right = 0;    // 保存游标
        int nowCost = 0, ans = 0;    // 保存已经花费的距离

        while (right < length){   // 移动右边的窗口位置
            nowCost += abs(s[right] - t[right]);

            // 如果窗口太大，移动左边窗口的位置
            while (nowCost > maxCost){   
                nowCost -= abs(s[left] - t[left]);
                left++;
            }
            right++;
            ans = max(ans, right - left);
        }
        
        return ans;
    }
};
```

