#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /**
     * 搜索旋转数组的最小值
     *  由于一定被旋转
     *      arr[mid] > arr[0] => mid 一定在左边上升，  l = mid + 1
     *      arr[mid] < arr[n - 1] && arr[mid] > arr[mid - 1] => mid 一定在右边上升的, r = mid - 1
     *      arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1] 这个值就是要找的值
     * @param  {vector<int>} nums :
     * @return {int}              :
     */
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] <= nums[n - 1])
            return nums[0];
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else if (nums[mid] < nums[r])
                r = mid;
        }
        // while (l <= r) {
        //     int mid = (l + r) >> 1;
        //     if (nums[mid] >= nums[0])
        //         l = mid + 1;    // 在左边上升的阶段,= 是考虑到 2 个元素的时候向右移动 与相同的值
        //     else if (nums[mid] < nums[n - 1] && nums[mid] > nums[mid - 1])
        //         r = mid - 1;    // 在右边上升且不是最小值
        //     else if (nums[mid] < nums[mid - 1])
        //         return nums[mid];
        // }
        return nums[l];
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    vector<int> arr{2,2,2,3,4,1};
    cout << so.findMin(arr) << endl;


    return 0;
}