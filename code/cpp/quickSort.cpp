#include <bits/stdc++.h>
using namespace std;

int patition(vector<int>& nums, int l, int r) {
    int idx = rand() % (r - l + 1) + l;
    swap(nums[r], nums[idx]);
    int pivot = l;
    int key = nums[r];
    for (int i = l; i < r; ++i) {
        if (nums[i] < key)
            swap(nums[pivot++], nums[i]);
    }
    swap(nums[pivot], nums[r]);
    return pivot;
}

int patition2(vector<int>& nums, int l, int r) {
    // int idx = rand() % (r - l + 1) + l;
    // swap(nums[l], nums[idx]);
    int keyV = nums[l];
    int i = l, j = r;
    while (i < j) {
        while (i < j && nums[j] > keyV) j--;   // 找到第一个比 keyV 小的，放到最左边
        nums[i] = nums[j];
        while (i < j && nums[i] < keyV) i++;    // 找到第一个比 KeyV 大的，放到右边
        nums[j] = nums[i];
    }
    nums[i] = keyV;
    return i;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int part = patition2(arr, left, right);
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
    vector<int> iv(arr, arr + 10);
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