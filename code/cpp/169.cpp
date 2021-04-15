#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 找到多数元素，摩尔投票法找到众数
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int cnt = 0;
        for (int num : nums) {
            if (num == candidate) {
                cnt++;
            }
            else if (--cnt < 0) {
                candidate = num;
                cnt = 1;
            }
        }
        return candidate;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}