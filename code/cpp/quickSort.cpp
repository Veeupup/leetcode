#include <bits/stdc++.h>
using namespace std;

/**
*   排序算法总结：https://zhuanlan.zhihu.com/p/252294913
*/

int patition(vector<int>& nums, int l, int r) {
    // int idx = rand() % (r - l + 1) + l;
    // swap(nums[r], nums[idx]);
    int pivot = l;
    int key = nums[r];
    for (int i = l; i < r; ++i) {
        if (nums[i] < key)
            swap(nums[pivot++], nums[i]);
    }
    swap(nums[pivot], nums[r]);
    return pivot;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int part = patition(arr, left, right);
        quickSort(arr, left, part - 1);
        quickSort(arr, part + 1, right);
    }
}

int main() {

    srand((unsigned)time(NULL));    // time seed
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 1000;
    }
    vector<int> iv(arr, arr + 30);
    // before sort
    for (int x : iv) {
        cout << x << ", ";
    }
    cout << endl << endl;

    // sort
    quickSort(iv, 0, iv.size() - 1);

    // after sort
    for (int x : iv) {
        cout << x << ", ";
    }
    cout << endl;



    return 0;
}