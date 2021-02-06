#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        int pre = INT_MIN;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (pre != nums[i]) {
                nums[idx++] = nums[i];
            }
            pre = nums[i];
        }
        return idx;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}