#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    *   轮转后的数组应该具有的性质
        先非递减，再非递减，也就是两个非递减数列
        可以一次遍历，首先找到第一个非递减数列的位置，再从这个位置开始到最后，如果确实旋转过，那么同时需要判断第一个元素和最后一个元素的大小
        
        [2,3,4,1] len=4 len-2=2 当 i=
    
    */
    bool check(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1)
            return true;
        int i = 0;
        for (; i <= len - 2; i++) {
            if (nums[i] > nums[i+1])
                break;  // 遇到第一个非递减的位置
        }
        if (i == len - 1)
            return true;    // 一直到最后一个元素都是递增的，没有进行过旋转
        for (++i; i <= len - 2; i++) {
            if (nums[i] > nums[i+1])
                return false;   // 第二次出现非递增
        }
        if ((i == len - 1) && (nums[len - 1] <= nums[0]))
            return true;
        return false;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}