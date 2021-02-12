#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 求平方根
     *
     * 1. 暴力模拟法
     *
     * 2. 二分法查找
     *
     * 例外情况：
     * 1.
     *
     * @param  {int} x :
     * @return {int}   :
     */
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
        // 1. 暴力法 
        //  
        // long i = 1;
        // long y = x;
        // for (; i < y;i++) {
        //     if (i * i == y)
        //         return i;
        //     else if (i * i > y)
        //         break;
        // }
        // return i - 1;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}