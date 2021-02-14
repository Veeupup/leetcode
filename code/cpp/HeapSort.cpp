#include <bits/stdc++.h>
using namespace std;

template<class T>
class HeapSort {
public:
    void sort(vector<T>& nums, int len) {
        for (int i = len >> 1 - 1; i >= 0; i--) {
            maxHeap(nums, len, i);
        }

        for (int j = len - 1; j >= 1; j--) {
            swap(nums[0], nums[j]);
            maxHeap(nums, j, 0);
        }
    }
private:
    void maxHeap(vector<T>& nums, int length, int index) {
        int leftIndex = index * 2 + 1;
        int rightIndex = index * 2 + 2;
        int maxIndex = index;

        if (leftIndex < length && nums[leftIndex] > nums[maxIndex])
            maxIndex = leftIndex;

        if (rightIndex < length && nums[rightIndex] > nums[maxIndex])
            maxIndex = rightIndex;

        if (index != maxIndex) {
            swap(nums[index], nums[maxIndex]);
            maxHeap(nums, length, index);
        }
    }
};

int main(int argc, char const* argv []) {

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
    HeapSort<int> heap;
    heap.sort(iv, iv.size());

    // after sort
    for (int x : iv) {
        cout << x << ", ";
    }
    cout << endl;


    return 0;
}