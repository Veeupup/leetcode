# Problem

【1365. 有多少小于当前数字的数字](https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/)

# Solution

## 1，排序+哈希表

排序，然后比每个元素小的就是它所在已排序数组中的下标（下标刚好 `-1`）

```c++
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // 1. 排序，哈希
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        map<int, int> num_index;
        for (int i = 0; i < temp.size(); i++) {
            if (num_index.find(temp[i]) == num_index.end())
                num_index[temp[i]] = i;
        }
        vector<int> res;
        for (auto num : nums) {
            res.emplace_back(num_index[num]);
        }
        return res;
    }
};

// 1. 暴力，时间复杂度 O(n^2)

// 2. 

// 3. 因为数据是从 1～100 的，可以采用计数
```

## 2, 计数

因为数字只从 1～100，所以完全可以使用 `cnt[i]`  来记录小于这个数的数字

```c++
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // 2. 计数
        vector<int> cnt(101, 0);
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            cnt[nums[i]]++;
        }
        for (int i = 1; i < 101; i++) {
            cnt[i] += cnt[i-1];
        }
        vector<int> ans;
        for (int i = 0; i < len; i++) {
            ans.emplace_back(nums[i] == 0 ? 0 : cnt[nums[i] - 1]);
        }

        return ans;
    }
};

// 1. 暴力，时间复杂度 O(n^2)

```

