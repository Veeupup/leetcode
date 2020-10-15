#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        vector<int> arr;
        for (auto hour : hours) {
            if (hour > 8)
                arr.emplace_back(1);
            else
                arr.emplace_back(-1);
        }

        // 计算前缀和数组
        vector<int> prefixSum;
        int currSum = 0;
        for (auto val : arr)
        {
            prefixSum.emplace_back(currSum);
            currSum += val;
        }
        prefixSum.emplace_back(currSum);

        // 保存一个单调递减的元素的下标和
        stack<int> staPos;
        for (int i = 0, size = prefixSum.size(); i < size; i++)
        {
            if (staPos.size() == 0 || prefixSum[staPos.top()] > prefixSum[i])
                staPos.push(i);
        }

        // 逆向遍历前缀和数组，找到最长的
        int res = 0;
        for (int j = prefixSum.size() - 1; j >= 0; j--)
        {
            while (staPos.size() != 0 && prefixSum[j] > prefixSum[staPos.top()])
            {
                res = max(res, j - staPos.top());
                staPos.pop();
            }
        }

        return res;
    }
};

int main()
{
    Solution *so = new Solution();
    vector<int> hours = {9,9,6,0,6,6,9};
    cout << so->longestWPI(hours) << endl;

    return 0;
}
