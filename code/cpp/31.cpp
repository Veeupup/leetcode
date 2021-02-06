#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 返回下一个更大的排列
     * @param  {vector<int>} nums : 
     */
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int len = nums.size();
        int i = len - 2, j = len - 1;
        while (i >= 0 && nums[i] >= nums[j]) {
            i--;
            j--;
        }
        if (i >= 0) {   // 不是最后一个排列，最后一个排列是全降序
            int k = len - 1;
            while (nums[i] >= nums[k]) {
                k--;
            }   // 找到第一个大于  nums[i] 的元素
            swap(nums[i], nums[k]);
        }
        // 将 [j, end) 逆序
        for (i = j, j = len - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}