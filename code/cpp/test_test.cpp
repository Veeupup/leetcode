#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int l, int r) {
    int x = rand() % (r - l + 1) + l;
    swap(nums[r], nums[x]);
    int key = nums[r];
    while (l < r) {
        while (l < r && nums[l] < key) ++l;
        nums[r] = nums[l];
        while (l < r && nums[r] >= key) --r;
        nums[l] = nums[r];
    }
    nums[l] = key;
    return l;
}

void quickSort(vector<int>& nums, int l, int r) {
    if (l < r) {
        int pos = partition(nums, 0, r);
        quickSort(nums, 0, pos - 1);
        quickSort(nums, pos + 1, r);
    }
}

void heap_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjustHeap(arr, i, n);
    }

    while (n-- > 0) {
        swap(arr[0], arr[n]);
        adjustHeap(arr, 0, n);
    }

}

void adjustHeap(vector<int>& arr, int i, int n) {
    int lson_idx = 2 * i + 1;
    int rson_idx = 2 * i + 2;
    int max_idx = i;

    if (lson_idx < n && arr[lson_idx] > arr[max_idx]) {
        max_idx = lson_idx;
    }

    if (rson_idx < n && arr[rson_idx] > arr[max_idx]) {
        max_idx = rson_idx;
    }

    if (max_idx != i) {
        swap(arr[i], arr[max_idx]);
        adjustHeap(arr, max_idx, n);
    }
}

int main(int argc, char const* argv []) {
    srand((unsigned)(time(NULL)));
    vector<int> nums;
    for (int i = 0; i < 10; i++) {
        nums.push_back(rand() % 100);
    }
    // quickSort(nums, 0, nums.size() - 1);
    heap_sort(nums);
    for (int x : nums)
        cout << x << ", ";
    cout << endl;


    return 0;
}