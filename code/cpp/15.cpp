#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 找到所有的和为 0 的三元组，可以将其转换为 二元组问题 
     * a + b + c = 0 => a + b = -c
     * 问题主要在于每个数字只能使用一次，可能包含重复的数字，主要问题在于处理重复的数字
     * 使用一个 map<int, int> =》 num, count 数组来保存每个数字可以使用的次数
     * 
     * 使用双指针，避免重复的关键在于不要选取重复的元素
     * 
     * @param  {vector<int>} nums     : 
     * @return {vector<vector<int>>}  : 
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int first = 0; first < n; ++first) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            int third = n - 1;
            int target = -1 * nums[first];
            for (int second = first + 1; second < n; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;   // 每次枚举的数字不一样
                while (second < third && nums[second] + nums[third] > target)
                    --third;
                if (second == third)
                    break;
                if (nums[second] + nums[third] == target)
                    res.emplace_back(vector<int> {nums[first], nums[second], nums[third]});
            }
        }
        return res;
    }
};

int main(int argc, char const* argv []) {

    vector<int> nums {-1,0,1,2,-1,-4};
    Solution so;
    auto res = so.threeSum(nums);
    for (auto vec : res) {
        for (auto x : vec)
            cout << x << ", ";
        cout << endl;
    }

    return 0;
}