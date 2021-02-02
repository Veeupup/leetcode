#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < target) {
                ++lo;
            }
            else if (sum > target) {
                --hi;
            }
            else if (sum == target) {
                return { lo, hi };
            }
        }
        return {};
    }
};

int main(int argc, char const* argv []) {




    return 0;
}