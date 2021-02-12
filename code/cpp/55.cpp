#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 动态规划
     *
     * dp[i] 代表能不能到达下一个目标
     *
     * @param  {vector<int>} nums :
     * @return {bool}             :
     */
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0)
            return false;
        // 暴力
        // int len = nums.size();
        // vector<bool> dp(len);
        // dp[0] = true;
        // for (int i = 0; i < len; i++) {
        //     if (dp[i]) {    // 能到达才计算
        //         for (int j = 1; j <= nums[i] && j + i < len; j++) {
        //             dp[i + j] = true;
        //         }
        //     }
        // }
        // return dp.back();

        // dfs
        int len = nums.size();
        int rightmost = 0;
        for (int i = 0; i < len; i++) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= len - 1)
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char const* argv []) {

    vector<int> arr{ 3,2,1,0,4 };
    Solution so;
    cout << so.canJump(arr) << endl;


    return 0;
}