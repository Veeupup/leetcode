#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 两数之和等于 target
     * 特殊情况： 1. nums.size() == 0
     *          2. target < nums[0] || target > nums.back() * 2
     * 思路：
     *  对于每个数 x, 通过二分找 target - x
     * @param  {vector<int>} nums : 
     * @param  {int} target       : 
     * @return {vector<int>}      : 
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int sum;
        while (l < r)
        {
            sum = nums[l] + nums[r];
            if (sum > target)
                r--;
            else if (sum < target)
                l++;
            else
                return vector<int> {nums[l], nums[r]};
        }
        return vector<int> {-1, -1};
        // if (nums.size() <= 1 || target < nums.front() || target > nums.back() * 2)
        //     return vector<int> {-1, -1};
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int tar2 = target - nums[i];
        //     int l = 0, r = nums.size() - 1;
        //     while (l <= r)
        //     {
        //         mid = l + (r - l) / 2;
        //         if (nums[mid] > tar2)
        //             r = mid - 1;
        //         else if (nums[mid] < tar2)
        //             l = mid + 1;
        //         else
        //             return vector<int> {nums[i], tar2};
        //     }
        // }
        // return vector<int> {-1, -1};
    }
};

int main()
{ 

    

    
    return 0;
}