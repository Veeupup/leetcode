#include <iostream>
#include <functional>
using namespace std;

template <typename T, typename F>
T func_wrapper(T t, F fun) {
    static int count = 0;
    cout << "fun 执行次数：" << ++count << endl;
    return fun(t);
}

int main(int argc, char const* argv []) {

    function<double(int)> squ_fun = [](int x) {
        return static_cast<double>(x);
    };

    func_wrapper(1, squ_fun);
    func_wrapper(1, squ_fun);
    func_wrapper(1, squ_fun);


    return 0;
}