#include <bits/stdc++.h>
using namespace std;

class Solution {
    int sum = 0;
    int n;
    int index[100010];
public:
    Solution(vector<int>& w) {
        n = w.size();
        for (int i = 0; i < n; i++) {
            sum += w[i];
            index[i] = sum;
        }
    }

    int pickIndex() {
        int x = rand() % sum;
        // 二分找对应的位置，例如
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (x > index[mid]) {
                l = mid + 1;
            }
            else if (x <= index[mid]) {
                r = mid;
            }
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main(int argc, char const* argv []) {

    vector<int> weight{ 1, 3, 2 };
    Solution so(weight);
    int idx[3] {0};
    for (int i = 0; i < 1000; i++) {
        int x = so.pickIndex();
        idx[x]++;
    }
    for (int i = 0; i < 3; ++i)
        cout << idx[i] << endl;
    

    return 0;
}