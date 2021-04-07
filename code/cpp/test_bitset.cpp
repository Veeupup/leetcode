#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const* argv []) {

    bitset<32> bits0;
    bitset<16> bits1(0xffff);
    bitset<16> bits2("1100");

    cout << bits0.any() << endl;
    cout << bits0.none() << endl;

    bits0.set(2);
    bits0.set(4);
    cout << bits0.any() << endl;
    cout << bits0.none() << endl;

    cout << bits0.size() << endl;
    cout << bits0.to_string() << endl;
    cout << bits0.test(2) << endl;
    cout << bits0.test(3) << endl;

    return 0;
}