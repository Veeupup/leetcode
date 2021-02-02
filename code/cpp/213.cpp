#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    /**
     * 环状数组，有三种可能：
     * 1. 第一间 最后一间 都不打劫
     * 2. 打劫第一间，不打劫最后一间
     * 3. 不打劫第一间，打劫最后一间 
     * @param  {vector<int>} nums : 
     * @return {int}              : 
     */
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(rob_range(nums,0, n-2), rob_range(nums,1, n-1));
    }
        
    int rob_range(vector<int>& nums, int start, int end) {
        if (start == end)
            return nums[start];
        int dp_i, dp_i_1 = 0, dp_i_2 = 0;
        for (int i = end; i >= start; i--) {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}