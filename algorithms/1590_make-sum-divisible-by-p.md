[TOC]

# Problem

给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。

请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。

子数组 定义为原数组中连续的一组元素。

 

```
示例 1：

输入：nums = [3,1,4,2], p = 6
输出：1
解释：nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4] ，剩余元素的和为 6 。
示例 2：

输入：nums = [6,3,5,2], p = 9
输出：2
解释：我们无法移除任何一个元素使得和被 9 整除，最优方案是移除子数组 [5,2] ，剩余元素为 [6,3]，和为 9 。
示例 3：

输入：nums = [1,2,3], p = 3
输出：0
解释：和恰好为 6 ，已经能被 3 整除了。所以我们不需要移除任何元素。
示例  4：

输入：nums = [1,2,3], p = 7
输出：-1
解释：没有任何方案使得移除子数组后剩余元素的和被 7 整除。
示例 5：

输入：nums = [1000000000,1000000000,1000000000], p = 3
输出：0


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= p <= 109
```



# Solution

这个题利用到 [974_和可被 K 整除的子数组](https://github.com/Veeupup/leetcode/blob/master/algorithms/974_subarray-sums-divisible-by-k.md) 的思想，可以先把上题弄清楚再回过头来看这道题目。

## 思路和分析

思路1，

首先求出数组所有元素的和 sum，如果能够被 p 整除，那么直接返回 0 即可，如果不能被整除，那么求出与 `dis = sum % p` ，然后在子数组中寻找能够整除  `p * k + dis` 的最短子数组即可（其中 `k = 0, 1, 2 , ...`）。

现在问题变成了如何求所有子数组的和，快速求出所有子数组的和，对于长度为 n 的数组，一共有` (n+1) * n / 2`个子数组，时间复杂度为 O(n<sup>2</sup>)

> 长度为 1 的有 n 个
>
> 长度为 2 的有 n-1 个
>
> …… 
>
> 长度为 a 的有 n - a 个
>
> 一共有 1 + 2 + …… + n = （n+1）n / 2



思路2，

假设 nums 的和除以 P，余数是 mod，

如果 mod == 0，答案就是 0。

如果 mod != 0，答案变成了找原数组中的最短连续子数组，使得其数字和除以 P，余数也是 mod。



由于是求解连续子数组和的问题，很容易想到使用**前缀和**。

> 前缀和 数组中前 i 个元素的和称之为 前缀和

我们可以扫描一遍整个数组，计算到每个元素的前缀和。

假设当前前缀和除以 P 的余数是 curmod，为了找到一段连续子数组对 P 的余数是 mod，我们需要找到一段前缀和，对 P 的余数是 targetmod。其中 targetmod 的求法是：

如果 curmod >= mod，很简单：targetmod = curmod - mod；

如果 curmod < mod，我们需要加上一个 P：targetmod = curmod - mod + P；

这样，我们可以保证，当前前缀和减去目标前缀和，剩余的数组对 P 的余数是 mod。我们只需要找最短的这样的数组就好。



最后，为了快速找到一段对 P 的余数为 targetmod 的前缀和，我们使用一个哈希表 table，来存储之前前缀和对 P 的余数和所在的索引。（key 为余数；value 为索引）。

table 在遍历过程中更新，以保证每次在 table 中查找到的，是离当前元素最近的索引，从而保证找到的是“最短”的连续子数组。



注意，此时需要设定 `table[0] = -1`，这是因为如果需要删除某个元素之前的所有元素，那么此时也就是 `targetmod = 0` 时，此时当前元素减去 `i - table[0]` 等于当前元素的下标加 1，这是因为数组的下标是从 0 开始的，如果设定为 0 ，那么将会比实际的长度少 1。



最终的返回值，如果需要将整个数组都删除才能满足要求，那么说明无法完成这个任务，那么输出 -1 ，否则输出正常的需要删除的值。



## code

```c++
class Solution
{
typedef long long ll;
public:
    int minSubarray(vector<int> &nums, int p){
        ll sum = 0;
        for (int e : nums) sum += e;
        ll mod = sum % (ll) p;

        if(mod == 0) return 0;

        int res = nums.size();
        unordered_map<int, int> table;
        // 如果之后需要将整个前缀删除时， 此时 targetmod = 0，
        // 而下标是从 0 开始的，如果删除 0 以及之前的内容需要加上 1，也就是减去 -1
        table[0] = -1;  

        sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (ll) nums[i];
            ll curmod = sum % p;    // 当前前缀和的余数
            table[curmod] = i;  // 记录余数为 curmod 的最靠后的位置，能保证输出的数组的长度最短

            ll targetmod = curmod >= mod ? curmod - mod : curmod - mod + p;
            if (table.count(targetmod)) {
                // 找之前是否有前缀和的余数为 targetmod，如果有 确认是否最小值
                res = min(res, i - table[targetmod]);
            }
        }
        return res == nums.size() ? -1 : res;
    }
```

