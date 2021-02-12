#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = nums[0];
        int preMax = INT_MIN;
        for (int x : nums) {
            preMax = max(x + preMax, x);
            ans = max(preMax, ans);
        }
        return ans;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}