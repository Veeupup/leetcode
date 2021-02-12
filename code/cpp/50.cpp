#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 快速幂
     * @param  {double} x :
     * @param  {int} n    :
     * @return {double}   :
     */
    double myPow(double x, int n) {
        if (x == 0.0)
            return 0.0;
        vector<double> pows;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double res = 1.0;
        while (n) {
            if (n & 1)
                res *= x;
            x *= x;
            n = n >> 1;
        }
        return res;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}