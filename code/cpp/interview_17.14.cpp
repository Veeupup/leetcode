#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int n = arr.size();
        if (k >= n)
            return arr;
        quickSort(arr, 0, n - 1, k);
        vector<int> vec;
        for (int i = 0; i < k; i++) {
            vec.push_back(arr[i]);
        }
        return vec;
    }

    void quickSort(vector<int>& arr, int left, int right, int k) {
        if (left < right) {
            int pos = partition(arr, left, right);
            int num = pos - left + 1;   // 排好序的数字个数
            if (num == k)
                return;
            else if (k < num)
                quickSort(arr, left, pos - 1, k);
            else
                quickSort(arr, pos + 1, right, k - num);
        }
    }

    int partition(vector<int>& arr, int left, int right) {
        int i = rand() % (right - left + 1) + left;
        swap(arr[i], arr[left]);
        int p = arr[left];
        while (left < right) {
            while (left < right && arr[right] >= p) right--;
            arr[left] = arr[right];
            while (left < right && arr[left] < p) left++;
            arr[right] = arr[left];
        }
        // 此时 left = right
        arr[left] = p;
        return left;
    }

    int partition2(vector<int>& arr, int left, int right) {
        if (left > right)
            return -1;
        int key = arr[right];
        int pos = left;
        for (int i = left; i < right; i++) {
            if (arr[i] < key)
                swap(arr[i], arr[pos++]);
        }
        swap(arr[right], arr[pos]);
        return pos;
    }
};

int main(int argc, char const* argv []) {

    vector<int> arr{ 1,3,5,7,2,4,6, 8 };
    Solution so;
    auto res = so.smallestK(arr, 4);
    for (int num : res) {
        cout << num << ", ";
    }

    return 0;
}