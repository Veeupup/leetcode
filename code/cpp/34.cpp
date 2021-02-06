#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) { // 结束是 left == right + 1, 此时是 right = mid - 1
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] == target) {
                right = mid - 1;
            }
        }
        if (left >= nums.size() || nums[left] != target)
            return vector<int> {-1, -1};
        int start = left;

        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] == target) {
                left = mid + 1;
            }
        }
        if (right < 0 || nums[right] != target)
            return vector<int> {-1, -1};

        return vector<int> {start, right};
    }
};

int main(int argc, char const* argv []) {




    return 0;
}