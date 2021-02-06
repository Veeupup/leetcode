#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 找到第一个大于等于 target 的元素
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        if (nums[nums.size() - 1] <= target)
            return nums.size();
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int mid = ((j - i) >> 1) + i;
            if (nums[mid] < target) {
                i = mid + 1;
            }
            else {
                j = mid;
            }
        }
        return i;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}