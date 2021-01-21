#include <bits/stdc++.h>
using namespace std;

// 0,2,3,4,5,6     l=0,r=5 mid=2 => l=0,r=1,mid=0 => l=1,r=1,mid=1 => r=mid-1=0
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
        // sort(nums.begin(), nums.end());
        // int pre = -1;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] != pre + 1)
        //         return nums[i] - 1;
        //     pre = nums[i];
        // }
        // return pre + 1;
    }
};

int main() {




    return 0;
}