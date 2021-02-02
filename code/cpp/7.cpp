#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 数字反转
     * @param  {int} x :
     * @return {int}   :
     */
    int reverse(int x) {
        long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res > INT_MAX || res < INT_MIN)
            return 0;
        return res;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.reverse(123) << endl;


    return 0;
}