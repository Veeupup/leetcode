#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        unordered_map<int, int> record = {{0, 1}};
        int sum = 0, ans = 0;
        for (int elem : A)
        {
            sum += elem;
            int mo = (sum % K + K) % K;
            if (record.count(mo))
            {
                ans += record[mo];
            }
            record[mo]++;
        }
        return ans;
    }
};

int main()
{
    Solution *so = new Solution();

    vector<int> arr{4,5,0,-2,-3,1};
    int K = 5;
    cout << so->subarraysDivByK(arr, K) << endl;
    
    return 0;
}
