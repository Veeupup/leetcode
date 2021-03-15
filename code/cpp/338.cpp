#include <bits/stdc++.h>
using namespace std;

/**
 *  x & (x - 1) 可以将 x 二进制位的最后一位 1 变成 0
 *
 */
class Solution {
public:
    vector<int> countBits(int num) {
        // 1. 暴力模式
        // vector<int> res(num + 1);
        // for (int i = 0; i <= num; i++) {
        //     int t = i, cnt = 0;
        //     while (t) {
        //         if (t & 1)
        //             cnt++;
        //         t >>= 1;
        //     }
        //     res[i] = cnt;
        // }
        // return res;
        // 2. 暴力模式优化
        // vector<int> res(num + 1);
        // for (int i = 0; i <= num; i++) {
        //     int t = i, cnt = 0;
        //     while (t) {
        //         t &= (t - 1);
        //         cnt++;
        //     }
        //     res[i] = cnt;
        // }
        // return res;
        // 3. 奇偶性分别判断 
        // 奇数 总比前面的偶数多 1 偶数除以 2 后 1 的个数不变，因为最低位是 0
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; i++) {
            if (i & 1) {
                res[i] = res[i - 1] + 1;
            }
            else {
                res[i] = res[i / 2];
            }
        }
        return res;

    }
};

int main(int argc, char const* argv []) {

    Solution so;
    auto res = so.countBits(5);
    for (int x : res) {
        cout << x << ", ";
    }
    cout << endl;


    return 0;
}