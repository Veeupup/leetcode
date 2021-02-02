#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1)
            return 0;
        int left = 0, right = height.size() - 1;
        int res = 0;
        while (left < right) {
            int val = (right - left) * min(height[left], height[right]);
            res = max(res, val);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}