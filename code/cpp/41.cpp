#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. sort 开始找
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n && nums[i] <= 0) {
            i++;
        }   // i 是第一个大于等于 0 的值
        int cnt = 1;
        for (; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] != cnt)
                return cnt;
            ++cnt;
        }
        return cnt;
    }

    // 1. hash
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (auto& x : nums) {
            if (x <= 0)
                x = n + 1;
        }
        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
            if (idx < n && nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};
    }
};

int main(int argc, char const* argv []) {




    return 0;
}