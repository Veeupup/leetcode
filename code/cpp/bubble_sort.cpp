#include <bits/stdc++.h>
using namespace std;

template <typename T>
void bubbleSort(T arr [], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main(int argc, char const* argv []) {

    int arr [] = { 2,31,1,3 };
    bubbleSort(arr, 4);
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << ", ";
    }


    return 0;
}