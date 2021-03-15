#include <bits/stdc++.h>
using namespace std;

class A {
private:
    const int limit;
    int& b;
public:
    A(int x) : limit(x), b(x) {

    }
};

class Test1 {
public:
    // Test1() {
    //     cout << "Test1 constrcutor" << endl;
    // }
    Test1(int x) : a(x) {};
    Test1(const Test1& test) {
        cout << "Test1 copy constructor" << endl;
        this->a = test.a;
    }
    Test1& operator=(const Test1& t1) {
        cout << "Test1 assignment constructor" << endl;
        this->a = t1.a;
        return *this;
    }
    int a;
};

class Test2 {
public:
    Test1 test1;
    Test2(Test1& test) : test1(test) {
        // this->test1 = test;
    }
};

int main(int argc, char const* argv []) {

    Test1 test(1);
    auto x = Test2(test);
    auto p = make_shared<int>(10);
    cout << p.use_count() << endl;
    auto q = make_shared<int>(1000);
    q = p;
    cout << p.use_count() << endl;
    auto q2 = p;
    cout << p.use_count() << endl;

    return 0;
}
