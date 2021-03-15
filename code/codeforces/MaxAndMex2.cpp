#include <bits/stdc++.h>
using namespace std;

int T, n, k;
int mul[100010];
int maxn = 0;
int minn = 0;
int main(int argc, char const* argv []) {
    cin >> T;
    while (T--) {
        memset(mul, 0, sizeof(mul));
        cin >> n >> k;
        maxn = 0;
        minn = 0;
        for (int i = 0; i < n; i++) {
            cin >> mul[i];
            maxn = max(maxn, mul[i]);/* code */
        }
        sort(mul, mul + n);
        for (int i = 0;i < n;i++) {
            if (minn != mul[i]) break;
            else minn++;
        }
        if (k == 0) {
            cout << n << endl;
            continue;
        }
        if (n == 1 && maxn == 0) {
            cout << n + k << endl;
        }
        else {
            // cout << maxn << minn << endl;
            if (maxn < minn) {
                cout << n + k << endl;
            }
            else {
                int yes = 1;
                int c = (maxn + minn + 1) / 2;
                for (int i = 0;i < n;i++) if (c == mul[i]) yes = 0;
                cout << n + yes << endl;
            }
        }

    }



    return 0;
}