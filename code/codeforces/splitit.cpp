#include <bits/stdc++.h>
using namespace std;
int T, n, k;
string s;


int main(int argc, char const* argv []) {

    cin >> T;
    while (T--) {
        cin >> n >> k;
        cin >> s;
        if (n == 2 * k) {
            cout << "NO" << endl;
        }
        else {
            int yes = 1;
            int len = s.length();
            for (int i = 0;i < k;i++) {
                if (s[i] != s[len - i - 1]) {
                    yes = 0;
                    break;
                }
            }
            if (yes == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }


    return 0;
}