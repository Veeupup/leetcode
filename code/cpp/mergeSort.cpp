#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> tmp;
public:
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1, cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                tmp[cnt++] = nums[i++];
            }else {
                tmp[cnt++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[cnt++] = nums[i++];
        }
        while (j <= r) {
            tmp[cnt++] = nums[j++];
        }
        for (int i = 0; i <= r - l; i++) {
            nums[l + i] = tmp[i];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        tmp.resize(n);
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}