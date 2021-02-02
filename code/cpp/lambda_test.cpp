#include <bits/stdc++.h>
using namespace std;

void test1() {
    vector<string> words{ "add", "dhuwofbiwaf", "dnwaionfw", "aaa", "c", " ", "dwa793" };

    stable_sort(words.begin(), words.end(),
        [](const string& a, const string& b) {
            return a.size() < b.size();
        });

    int sz = 5;
    auto wc = find_if(words.begin(), words.end(),
        [sz](const string& a) {
            return a.size() > sz;
        });
    auto count = words.end() - wc;
    cout << count << endl;

    for_each(words.begin(), words.end(),
        [](const string& a) {
            cout << a << endl;
        });

    cout << "=============" << endl;
}

void q10_14() {
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    int x = add(1, 2);
    cout << x << endl;
    cout << "=============" << endl;
}

void q10_15() {
    int x = 10;
    auto addx = [x](int a) {
        return x + a;
    };

    int res = addx(5);
    cout << res << endl;

    cout << "=============" << endl;
}

void q10_16() {
    int x = 1 or 0;
    cout << x << endl;
}

int main(int argc, char const* argv []) {

    test1();
    q10_14();
    q10_15();
    q10_16();

    return 0;
}