#include <bits/stdc++.h>
using namespace std;

mutex latch;
void  func() {
    latch.unlock();
    printf("Unlock successfully\n");
}

int main(int argc, char const* argv []) {

    latch.lock();
    thread t1(func);
    thread t2(func);
    thread t3(func);
    t1.join();
    t2.join();
    t3.join();

    return 0;
}