#include <bits/stdc++.h>
using namespace std;

void myFun(int x);
typedef int (*PTRFUN) (int, int);
PTRFUN ff;

int max2(int a, int b) {
    return a > b ? a : b;
}

int main(int argc, char const* argv []) {

    myFun(100);

    int(*myfun)(int, int) = max2;
    cout << myfun(1, 3) << endl;
    ff = max2;
    cout << ff(2,3) << endl;

    return 0;
}

void myFun(int x) {
    cout << x << endl;
}
