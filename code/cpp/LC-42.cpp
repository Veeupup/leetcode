#include <bits/stdc++.h>
using namespace std;

/**
* 连续子数组和的最大，动态规划
    对于 val(k) = max(val(k-1), val(k-1)+nums[k]); 
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> sum(nums.size());
        sum[0] = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            sum[i] = max(sum[i-1]+nums[i], nums[i]);
            maxSum = max(sum[i], maxSum);
        }
        return maxSum;
    }
};

int main()
{ 
    Solution so;
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> iv(arr, arr+9);
    cout << so.maxSubArray(iv) << endl;

    return 0;
}