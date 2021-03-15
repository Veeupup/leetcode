#include <bits/stdc++.h>
using namespace std;

class A {
private:
    int a;
public:
    A() : a(100) {};
    A(const A& a2) {
        this->a = a2.a;
    }
    int func(A& a2) {
        cout << ++a2.a << endl;
    }
};

class B {
public:
    int func(const A& a) {
        // cout << a.a << endl;
    }
};


int main(int argc, char const* argv []) {

    A a;
    A a2(a);
    a2.func(a);


    return 0;
}