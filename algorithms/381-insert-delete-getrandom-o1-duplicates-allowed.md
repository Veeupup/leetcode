[381. O(1) 时间插入、删除和获取随机元素 - 允许重复](https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)

设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。

注意: 允许出现重复元素。

insert(val)：向集合中插入元素 val。
remove(val)：当 val 存在时，从集合中移除一个 val。
getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。

# Solution

思路一，哈希表

为了使得 `O(1)` 时间内能够随机获取一个元素，我们将每个数值(可以重复)存储在一个列表nums中。这样，获取随机元素时，只需要随机生成一个列表中的索引，就能够得到一个随机元素。

这样做的问题在于:列表中的随机删除并不是 `O(1)` 的。然而我们可以发现，列表中元素的顺序是无关紧要的，只要它们正确地存在于列表中即可。因此，在删除元素时，我们可以将被删的元素与列表中最后一个元素交换位置，随后便可以在 `O(1)` 时间内，从列表中去除该元素。

这需要我们额外维护数值在列表中每一次出现的 下标集合。对于数值val而言，记其下标集合为S<sub>idx</sub>。

在删除时，我们找出val出现的其中一个下标i,并将nums[i]与nums[nums.length- 1]交换。随后，将i从S<sub>val</sub>中去除，并将S<sub>nums[nums.length-1]</sub> 中原有的nums[nums.len.gth- 1]替换成i。由于集合的每个操作都是 `O(1)` 的，因此总的平均时间复杂度也是 `O(1)` 的。

```c++
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> idx;
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        idx[val].insert(nums.size() - 1);
        return idx[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (idx.find(val) == idx.end()) {
            return false;
        }
        int i = *(idx[val].begin());
        nums[i] = nums.back();
        idx[val].erase(i);
        idx[nums[i]].erase(nums.size() - 1);
        if (i < nums.size() - 1) {
            idx[nums[i]].insert(i);
        }
        if (idx[val].size() == 0) {
            idx.erase(val);
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

```

**复杂度分析**

- 时间复杂度：O(1)。
- 空间复杂度：O(N)，其中 N 为集合中的元素数目。

