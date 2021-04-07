#include <bits/stdc++.h>
using namespace std;

class Singelton {
private:
    Singelton() {};
    int age;
public:
    static mutex latch;
public:
    static Singelton* getInstance() {
        static Singelton instance;
        return &instance;
    }
};

int main(int argc, char const* argv []) {

    Singelton* ra = Singelton::getInstance();
    Singelton::latch.lock();
    ///
    Singelton::latch.unlock();


    return 0;
}