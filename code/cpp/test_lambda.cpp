#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const* argv []) {

    int outer = 20;
    int aa = 20;

    auto f = [aa, &outer]() mutable {
        outer += 22;
        aa += 22;
    };

    f();
    cout << outer << endl;
    cout << aa << endl;

    return 0;
}