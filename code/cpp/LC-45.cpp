#include <bits/stdc++.h>
using namespace std;

/**
* 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

首先是暴力方法，有 n! 种排列方式，暴力找到最小的

然后是排序，这个时候排序的比较函数不一样了，应该比较两个数字，谁放在前面会比较小

30, 9 正常 9 < 30，但是

*/

class Solution
{
public:
    string minNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), cmp);
        string res;
        for (auto x : nums)
            res += to_string(x);
        return res;
    };

    static bool cmp(int x, int y)
    {
        int s_x = x, s_y = y;
        int num_x = 0, num_y = 0; // x, y 的位数
        while (s_x)
        {
            num_x++;
            s_x /= 10;
        }
        while (s_y)
        {
            num_y++;
            s_y /= 10;
        }
        return x * pow(10, max(num_y, 1)) + y < y * pow(10, max(num_x, 1)) + x;
    }
};

int main()
{
    Solution so;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector<int> iv(arr, arr + 10);
    cout << so.minNumber(iv) << endl;

    return 0;
}