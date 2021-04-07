#include <bits/stdc++.h>

#define NDEBUG
#include <assert.h>
using namespace std;

using ll = long long;
const ll MM = 1e9 + 7;

ll pw(ll p, ll q) {
    ll ret = 1;
    for (; q; q >>= 1) {
        if (q & 1) ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

class Solution {
public:
    int maxNiceDivisors(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 3;
        if (n % 3 == 0)
            return pw(3, n / 3);
        if (n % 3 == 1)
            return pw(3, (n - 4) / 3) * 4 % MM;
        if (n % 3 == 2)
            return pw(3, n / 3) * 2 % MM;
    }
};

int main(int argc, char const* argv []) {

    cout << pw(2, 80) << endl;
    assert(1 == 2);

    return 0;
}