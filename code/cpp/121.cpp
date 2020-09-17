#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1)
            return 0;
        int best = 0, low = prices[0], high = prices[0];
        for (int i = 1; i < len; i++)
        {
            int temp = prices[i] - low;
            best = temp > best ? temp : best;
            low = prices[i] < low ? prices[i] : low;
        }
        return best;        
    }
};

int main() {
    Solution *so = new Solution();

    vector<int> arr{7,1,5,3,6,4};
    cout << so->maxProfit(arr) << endl;

    arr = {7,6,4,3,1};
    cout << so->maxProfit(arr) << endl;

    return 0;
}
