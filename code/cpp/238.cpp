#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int length = nums.size();

        vector<int> output(length);

        // 计算左边的数字乘积
        output[0] = 1;
        for (int i = 1; i < length; i++)
        {
            output[i] = output[i-1] * nums[i-1];
        }

        // 最开始最右边应该为 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--)
        {
            output[i] = output[i] * R;
            R = nums[i] * R;
        }
        
        return output;
    }
};

int main()
{
    Solution *so = new Solution();

    vector<int> arr{1, 2, 3, 4};
    vector<int> output = so->productExceptSelf(arr);
    vector<int>::iterator it;
    for (it = output.begin(); it != output.end(); it++)
    {
        cout << *it << ",";
    }
    
    return 0;
}
