#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (len < 2 || nums[i] != nums[len - 2])
                nums[len++] = nums[i];
        }
        return len;

        // int n = nums.size();
        // if (n <= 2)
        //     return n;
        // int idx = 2;
        // int pre = nums[0], pre_pre = nums[1];
        // for (int i = 2; i < n; i++) {
        //     if ((nums[i] != pre) || (nums[i] == pre && nums[i] != pre_pre)) {
        //         nums[idx] = nums[i];
        //         pre = nums[idx];
        //         pre_pre = nums[idx - 1];
        //         idx++;
        //     }
        // }
        // return idx;
    }
};

int main(int argc, char const* argv []) {

    vector<int> arr{ 1,1,2,2,3 };
    Solution so;
    cout << so.removeDuplicates(arr) << endl;


    return 0;
}