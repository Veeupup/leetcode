#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. 调用系统 sort
    // 2. 手写快排
    // 3. 优先队列
    // 4. 快排思想找
    int partition(vector<int>& nums, int l, int r) {
        int nex = l + rand() % (r - l + 1);
        swap(nums[r], nums[nex]);
        int key = nums[r];
        while (l < r) {
            while (l < r && nums[l] < key) ++l;
            nums[r] = nums[l];
            while (l < r && nums[r] >= key) --r;
            nums[l] = nums[r];
        }
        nums[l] = key;
        return l;
    }

    void quick_sort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int pos = partition(nums, l, r);
        quick_sort(nums, l, pos - 1);
        quick_sort(nums, pos + 1, r);
    }

    int findKthLargest(vector<int>& nums, int k) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
};

int main(int argc, char const *argv[])
{ 

    vector<int> arr {3,2,3,1,2,4,5,5,6};
    Solution so;
    so.findKthLargest(arr, 2);

    
    return 0;
}