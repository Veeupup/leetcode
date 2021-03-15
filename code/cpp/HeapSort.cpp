#include <bits/stdc++.h>
using namespace std;

/**
 *
 *  https://www.cnblogs.com/chengxiao/p/6129630.html
 *  https://zhuanlan.zhihu.com/p/252294913
 *
 */

template<class T>
class HeapSort {
public:
    void sort(vector<T>& nums, int len) {
        for (int i = len / 2 - 1; i >= 0; i--) {
            maxHeap(nums, len - 1, i);
        }

        for (int j = len - 1; j >= 1; j--) {
            swap(nums[0], nums[j]);
            maxHeap(nums, j - 1, 0);
        }
    }
private:
    void maxHeap(vector<T>& nums, int end, int index) {
        int leftIndex = index * 2 + 1;
        int rightIndex = index * 2 + 2;
        int maxIndex = index;

        if (leftIndex <= end && nums[leftIndex] > nums[maxIndex])
            maxIndex = leftIndex;

        if (rightIndex <= end && nums[rightIndex] > nums[maxIndex])
            maxIndex = rightIndex;

        if (index != maxIndex) {
            swap(nums[index], nums[maxIndex]);
            maxHeap(nums, end, maxIndex);   // 交换之后，maxIndex 位置的值变小了，需要继续向下调整
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