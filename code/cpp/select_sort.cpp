#include <bits/stdc++.h>
using namespace std;

template <typename T>
void select_sort(T arr [], int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[minIdx], arr[i]);
    }
}

int main(int argc, char const* argv []) {

    int arr [] = { 2,31,1,3 };
    select_sort(arr, 4);
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << ", ";
    }


    return 0;
}