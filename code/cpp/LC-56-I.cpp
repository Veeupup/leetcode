#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 找到数组中两个只出现一次的元素，要求时间复杂度为 O(n),空间复杂度为 O(1)
     * 思路：
     *  1. 用 set 保存，如果出现第二次，那么就剔除
     *  2. 
     * @param  {vector<int>} nums : 
     * @return {vector<int>}      : 
     */
    vector<int> singleNumbers(vector<int>& nums) {
        int k = 0;  // 0 异或任何数等于任何数
        for (auto x : nums) {
            k ^= x;
        }
        int mask = 1;
        while ((k & mask) == 0) {
            mask <<= 1;
        }
        int a = 0, b = 0;
        for (auto x : nums) {
            if ((mask & x) {
                a ^= x;
            }else {
                b ^= x;
            }
        }
        return vector<int> {a, b};
    }
};

int main()
{ 

    

    
    return 0;
}