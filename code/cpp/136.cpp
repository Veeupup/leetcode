#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1, n = nums.size(); i < n; i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}