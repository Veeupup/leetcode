#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 2 2 2 1 2
    // 2 2 2 2 2 2 2 2 2 2 1 2 2 2
    // 2 2 2 1 2 2 2 2 2 2 2 2 2 
    /**
     * 有重复元素
     *  l = 0, r = n - 1
     *  nums[mid] > nums[0] => 一定在右边 l = mid + 1
     *  不然的话，
     *  nums[mid] == nums[0] => 可能在右边也可能在左边，需要和 mid + 1, mid - 1 比较来判断，能判断出来吗？也不行，因为 如果很多重复的，+1 -1 也不行
     *  nums[mid] < nums[]
     * @param  {vector<int>} nums : 
     * @return {int}              : 
     */
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (nums[l] < nums[r])
            return nums[l];
        while (l < r) {
            int mid = l + (r - l) / 2;
            
                
        }
    }
};

int main(int argc, char const* argv []) {




    return 0;
}