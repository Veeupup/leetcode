#include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        sum.resize(nums.size());
        if (nums.size() == 0)
            return;
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0)
            return sum[j];
        return sum[j] - sum[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

 /**
  * Your NumArray object will be instantiated and called as such:
  * NumArray* obj = new NumArray(nums);
  * int param_1 = obj->sumRange(i,j);
  */

int main(int argc, char const* argv []) {




    return 0;
}