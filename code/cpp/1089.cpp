#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                for (int j = arr.size() - 1; j > i; j--)
                {
                    arr[j] = arr[j - 1];
                }
                i++;
            }
        }
    }
};

int main()
{
    Solution *so = new Solution();

    vector<int> arr{1, 0, 2, 3, 0, 4, 5, 0};
    so->duplicateZeros(arr);

    arr = {1, 2, 3, 4};
    so->duplicateZeros(arr);

    return 0;
}
