#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 最接近的三数之和
     * 双指针法，首先要去掉重复元素，
     *
     * 一个指针在前，一个指针在后，找到和大于 target 和小于 target 的元素，然后比较这两个
     *
     * 暴力法
     *
     * @param  {vector<int>} nums :
     * @param  {int} target       :
     * @return {int}              :
     */
    int threeSumClosest(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // int ans = INT_MIN;
        // for (int first = 0; first < n; ++first) {
        //     if (first > 0 && nums[first] == nums[first - 1])
        //         continue;
        //     for (int second = first + 1; second < n; ++second) {
        //         if (second > first + 1 && nums[second] == nums[second - 1])
        //             continue;
        //         for (int third = second + 1; third < n; ++third) {
        //             if (third > second + 1 && nums[third] == nums[third - 1])
        //                 continue;
        //             int sum = nums[first] + nums[second] + nums[third];
        //             ans = abs(sum - target) > abs(ans - target) ? ans : sum;
        //         }
        //     }
        // }

        sort(nums.begin(), nums.end());
        int ans = 1e7;
        
        // [&] / [=] 捕获运算符，显式出现时自动捕获所有的 *this
        auto update = [&](int cur) {
            ans = abs(cur - target) > abs(ans - target) ? ans : cur;
        };
        
        int n = nums.size();
        for (int first = 0; first < n; ++first) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            int left = first + 1;
            int right = n - 1;
            while(left < right) {
                int sum = nums[first] + nums[left] + nums[right];
                update(sum);
                if (ans == target)
                    return target;
                if (sum > target) {
                    int _right = right - 1;
                    while (_right > left && nums[_right] == nums[right])
                        --_right;
                    right = _right;
                }              
                else {
                    int _left = left + 1;
                    while (_left < right && nums[_left] == nums[left])
                        ++_left;
                    left = _left;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const* argv []) {

    vector<int> vec {-1,2,1,-4};
    int target = 1;
    Solution so;
    cout << so.threeSumClosest(vec, target) << endl;


    return 0;
}