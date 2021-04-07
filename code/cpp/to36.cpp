#include <bits/stdc++.h>
using namespace std;

char getChar(int x) {
    if (x < 10) {
        return x + '0';
    }
    return x - 10 + 'a';
}

string to36(int num) {
    string ans;
    while (num) {
        ans += getChar(num % 36);
        num /= 36;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main(int argc, char const* argv []) {

    cout << to36(314) << endl;
    cout << to36(9) << endl;
    cout << to36(3145) << endl;


    return 0;
}