#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[l] == nums[mid]) {
                l++;
                continue;
            }
            if (nums[l] < nums[mid]) { // [0, mid] 有序
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else {  // [mid, ..., n-1] 有序
                if (target <= nums[r] && target > nums[mid]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}