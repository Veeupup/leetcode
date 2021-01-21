#include <bits/stdc++.h>
using namespace std;

/**
 *  有多少种组合，数字只能是一位或者两位，遍历所有的可能计算
 * 
 *  
*/

class Solution
{
public:
    vector<int> nums;
    int translateNum(int num)
    {
        // 动态规划 f(i) = f(i-1) + f(i-2)
        return f(num);
        // if (num < 0)
        //     return 0;
        // while (num)
        // {
        //     nums.emplace_back(num % 10);
        //     num /= 10;
        // }
        // reverse(nums.begin(), nums.end());
        // int res = 0;
        // transN(0, nums.size() - 1, res);
        // return res;
    }

    int f(int num)
    {
        if (num < 10)
            return 1;
        if (num % 100 <= 25 && num % 100 >= 10)
            return f(num / 100) + f(num / 10);
        else
            return f(num / 10);
    }

    void transN(int start, int end, int &res)
    {
        if (start >= end)
        {
            ++res;
            return;
        }
        if (nums[start] >= 0 && nums[start] <= 25)
            transN(start + 1, end, res);
        if (start < end)
        {
            int test2 = nums[start] * 10 + nums[start + 1];
            if (test2 >= 10 && test2 <= 25)
                transN(start + 2, end, res);
        }
    }
};

int main()
{
    Solution so;
    int x = 12258;
    cout << so.translateNum(x) << endl;

    return 0;
}