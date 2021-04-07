#include <bits/stdc++.h>
using namespace std;

class Useless {
private:
    int n;
    char* ptr;
public:
    Useless() : n(0), ptr(nullptr) {}
    Useless(int n, char ch) : n(n) {
        cout << "default constructor" << endl;
        ptr = new char[n];
        for (int i = 0; i < n; i++)
            ptr[i] = ch;
    }
    ~Useless() {
        delete ptr;
    }
    // copy constructor
    Useless(const Useless& oth) {
        if (&oth == this)
            return;
        cout << "copy constructor" << endl;
        n = oth.n;
        ptr = new char[n];
        for (int i = 0; i < n; ++i) {
            ptr[i] = oth.ptr[i];
        }
    }
    // move copy constuctor
    Useless(Useless&& oth) {
        cout << "move copy constuctor" << endl;
        n = oth.n;
        ptr = oth.ptr;
        oth.n = 0;
        oth.ptr = nullptr;
    }
    // assignment constuctor
    Useless& operator=(const Useless& oth) {
        cout << "assignment constructor" << endl;
        n = oth.n;
        ptr = new char[n];
        for (int i = 0; i < n; ++i) {
            ptr[i] = oth.ptr[i];
        }
    }
    // move assignment constuctor
    Useless& operator=(Useless&& oth) {
        if (&oth == this)
            return *this;
        cout << "move assignment constuctor" << endl;
        n = oth.n;
        ptr = oth.ptr;
        oth.n = 0;
        oth.ptr = nullptr;
    }
    void showObject() {
        for (int i = 0; i < n; i++)
            cout << ptr[i];
        cout << endl;
        cout << (void*)ptr << endl;
    }
    Useless operator+(const Useless& f) {
        return Useless(n + f.n, 'a');
    }
};


int main(int argc, char const* argv []) {

    Useless u1(10, 'a');
    cout << "u1: ";
    u1.showObject();

    Useless u2(u1);
    cout << "u2: ";
    u2.showObject();

    Useless u3(std::move(u1));
    cout << "u3";
    u3.showObject();

    Useless u9 = std::move(u2);
    u9 = u3;

    vector<Useless> vec;
    vec.push_back(Useless(10, 'a'));
    vec.push_back(Useless(10, 'b'));



    return 0;
}