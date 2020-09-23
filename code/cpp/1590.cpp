#include <bits/stdc++.h>
using namespace std;

class Solution
{
typedef long long ll;
public:
    int minSubarray(vector<int> &nums, int p){
        ll sum = 0;
        for (int e : nums) sum += e;
        ll mod = sum % (ll) p;

        if(mod == 0) return 0;

        int res = nums.size();
        unordered_map<int, int> table;
        // 如果之后需要将整个前缀删除时， 此时 targetmod = 0，
        // 而下标是从 0 开始的，如果删除 0 以及之前的内容需要加上 1，也就是减去 -1
        table[0] = -1;  

        sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (ll) nums[i];
            ll curmod = sum % p;    // 当前前缀和的余数
            table[curmod] = i;  // 记录余数为 curmod 的最靠后的位置，能保证输出的数组的长度最短

            ll targetmod = curmod >= mod ? curmod - mod : curmod - mod + p;
            if (table.count(targetmod)) {
                // 找之前是否有前缀和的余数为 targetmod，如果有 确认是否最小值
                res = min(res, i - table[targetmod]);
            }
        }
        return res == nums.size() ? -1 : res;
    }
};

int main()
{

    Solution *so = new Solution();

    vector<int> arr{3, 1, 4, 2};
    int p = 6;
    cout << so->minSubarray(arr, p) << endl;

    arr = {6, 3, 5, 2};
    p = 9;
    cout << so->minSubarray(arr, p) << endl;

    arr = {1, 2, 3};
    p = 3;
    cout << so->minSubarray(arr, p) << endl;

    arr = {1, 2, 3};
    p = 7;
    cout << so->minSubarray(arr, p) << endl;

    arr = {1000000000, 1000000000, 1000000000};
    p = 3;
    cout << so->minSubarray(arr, p) << endl;

    arr = {26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3};
    p = 26;
    cout << so->minSubarray(arr, p) << endl;

    return 0;
}
