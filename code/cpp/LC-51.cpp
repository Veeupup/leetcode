#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     *  采用归并排序来进行寻找逆序对
     * @param  {vector<int>} nums :
     * @return {int}              :
     */
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }

    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r)
            return 0;

        int mid = l + (r - l) / 2;
        int leftCount = mergeSort(nums, tmp, l, mid);
        int rightCount = mergeSort(nums, tmp, mid + 1, r);
        int nowCount = 0;
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                nowCount += (j - (mid + 1));
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        while (i <= mid) {
            tmp[pos++] = nums[i++];
            nowCount += (j - (mid + 1));
        
        while (j <= r) {
            tmp[pos++] = nums[j++];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return leftCount + rightCount + nowCount;
    }
};

int main() {

    int arr [] = { 7,5,6,4 };
    vector<int> iv(arr, arr + 4);
    Solution so;
    cout << so.reversePairs(iv) << endl;

    return 0;
}