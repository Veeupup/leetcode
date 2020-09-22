#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int MAX = 50000 * 500 + 1;

public:
    int shipWithinDays(vector<int> &weights, int D)
    {
        int hi = MAX, lo = 0, mid;
        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2;
            if (canShip(weights, D, mid)) {
                hi = mid;
            }else {
                lo = mid + 1;
            }
        }
        return lo;
    }

private:
    bool canShip(vector<int> &weight, int D, int K)
    {
        int remain = K; // 当前船剩余载重量
        for (auto wei : weight) {
            if (wei > K) return false;
            if (remain < wei) {
                remain = K;
                D--;
            }
            remain -= wei;
        }
        return D > 0;
    }
};

int main()
{
    Solution *so = new Solution();

    vector<int> arr{1,2,3,4,5,6,7,8,9,10};
    int D = 5;
    cout << so->shipWithinDays(arr, D) << endl;

    return 0;
}
