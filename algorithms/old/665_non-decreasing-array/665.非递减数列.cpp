/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0, len = nums.size();
        for (int i = 1; i < len && cnt <= 1; i++)
        {
            if (nums[i-1] > nums[i]){
                cnt++;
                if(i - 2 >= 0 && nums[i-2] > nums[i]) nums[i] = nums[i-1];
            }   
        }
        return cnt <= 1;
    }
};
// @lc code=end

