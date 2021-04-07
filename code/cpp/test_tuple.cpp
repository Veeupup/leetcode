#include <bits/stdc++.h>
using namespace std;

tuple<double, char, string> get_stu(int id) {
    if (id == 0) return make_tuple(3.8, 'A', "Lisa Simpson");
    if (id == 1) return make_tuple(2.9, 'C', "Milhouse Van Houten");
    if (id == 2) return make_tuple(1.7, 'D', "Ralph Wiggum");
    throw std::invalid_argument("id");
}

int main(int argc, char const* argv []) {

    tuple<int, vector<int>, double> someVal(10, { 1, 2, 3 }, 1.1);

    cout << get<0>(someVal) << endl;
    auto& vec = get<1>(someVal);    // 使用引用的方式获取，才能修改，不然返回的是值
    vec[1] = 11;
    // (get<1>(someVal))[1] = 11;
    for (int x : get<1>(someVal)) {
        cout << x << endl;
    }

    auto stu = get_stu(1);
    cout << get<2>(stu) << endl;

    return 0;
}