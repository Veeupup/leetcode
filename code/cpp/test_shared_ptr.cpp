#include <bits/stdc++.h>
using namespace std;

class A {
public:
    int a;
    A(int a) :a(a) {};
};

int main(int argc, char const* argv []) {

    A* a1 = new A(10);
    auto del_fun = [](A* aa) {
        aa->a = 20;
        cout << "del func invoked " << aa->a << endl;
        delete aa;
    };
    {
        shared_ptr<A> sp_a(a1, del_fun);
    }


    return 0;
}