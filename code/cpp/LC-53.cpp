#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    /**
     * 统计在排序数组中 target 出现的次数
     * 首先通过二分查找找到该数字的位置，然后前后查找
     * @param  {vector<int>} nums : 
     * @param  {int} target       : 
     * @return {int}              : 
     */
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int pos = -1;
        while (l <= r)  // 必须是等于，只有一个元素的时候才能监测到
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            }            
            else if (nums[mid] < target) {
                l = mid + 1;
            }            
            else {
                pos = mid;
                break;
            }
        }
        if (pos == -1)
            return 0;
        int count = 0;
        int i = pos-1, j = pos + 1;
        while (i >= 0 && nums[i] == target) {
            --i;
            count++;
        }
        while (j < nums.size() && nums[j] == target) {
            ++j;
            count++;
        }
        return count;
    }
};

int main()
{ 

    

    
    return 0;
}