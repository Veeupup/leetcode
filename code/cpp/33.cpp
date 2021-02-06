#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 搜索旋转排序数组
     *
     * 1. 暴力法
     *
     * 2. 二分法
     *  先找到分界的点在哪，再根据 target 和分界点的位置去找
     *
     *
     * @param  {vector<int>} nums :
     * @param  {int} target       :
     * @return {int}              :
     */
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[0] <= nums[mid]) {  // [0, mid] 有序，左边有序
                if (target >= nums[0] && target < nums[mid]) {  // target 在有序的左边
                    r = mid - 1;
                }
                else {  // target 在右边
                    l = mid + 1;
                }
            }
            else {  // 右边有序
                if (target <= nums[nums.size() - 1] && target > nums[mid]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}