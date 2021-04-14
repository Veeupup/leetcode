#include <iostream>
#include <vector>
using namespace std;

struct dish {
    string name;
    vector<int> dishes;
};

void move(int n, dish& A, dish& B, dish& C) {
    if (n == 1) {
        int x = A.dishes.back();
        C.dishes.push_back(x);
        A.dishes.pop_back();
        cout << "move " << x << " from " << A.name << " to " << C.name << endl;
    }
    else {
        move(n - 1, A, C, B);
        move(1, A, B, C);
        move(n - 1, B, A, C);
    }
}

int main() {
    dish A{ "A", {3,2,1} };
    dish B{ "B", {} };
    dish C{ "C", {} };
    move(3, A, B, C);

    return 0;
}
