#include <bits/stdc++.h>
using namespace std;

template <typename T>
void insert_sort(T arr [], int len) {
    for (int i = 1; i < len; i++) {
        T cur = arr[i];
        int preIdx = i - 1;
        while (preIdx >= 0 && arr[preIdx] > cur) {
            arr[preIdx + 1] = arr[preIdx];
            preIdx--;
        }
        arr[preIdx + 1] = cur;
    }
}

int main(int argc, char const* argv []) {

    int arr [] = { 2,31,1,3 };
    insert_sort(arr, 4);
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << ", ";
    }

    return 0;
}