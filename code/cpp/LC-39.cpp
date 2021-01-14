#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore votes
        int res = -1, votes = 0;
        for (auto num : nums) {
            if (!votes)
                res = num;
            votes += res == num ? 1 : -1;
        }
        return res;
        // vector<int> iv(nums.size(), 0);
        // int half = nums.size() / 2;
        // for (auto x : nums) {
        //     int idx = x % nums.size();
        //     if (idx < 0)
        //         idx += nums.size();
        //     if (++iv[idx] > half)
        //         return x;
        // }
        // return -1;
    }
};

int main() {
    int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
    vector<int> iv(arr, arr + 9);
    Solution so;
    cout << so.majorityElement(iv) << endl;


    return 0;
}