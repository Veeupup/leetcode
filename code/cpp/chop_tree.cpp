#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int check(vector<int>& trees, int m) {
        int res = 0;
        for (int x : trees)
            res += x / m;
        return res;
    }

    int chopTree(vector<int>& trees, int k) {
        int max_val = *max_element(trees.begin(), trees.end());
        cout << max_val << endl;
        int l = 1, r = max_val;
        while (l < r) {
            int mid = (l + r + 1) >> 1; // 要选择靠右的，不然 3 4 就一直是 3，因为左边不动，所以最后就要选择靠右边的
            if (check(trees, mid) >= k)
                l = mid;    // 肯定这里以及右边
            else
                r = mid - 1;// mid 不行，肯定比 mid 小
        }
        return l;
    }

};



int main(int argc, char const* argv []) {

    Solution so;
    vector<int> trees{ 4, 7, 2, 10, 5 };
    cout << so.chopTree(trees, 5) << endl;


    return 0;
}