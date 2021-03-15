#include <bits/stdc++.h>
using namespace std;

/**
 *  计数排序，只适用于小范围的排序
 */
const int BUCKET_NUM = 101;
// 假设数据都小于 100
void counting_sort(int arr [], int len) {
    vector<int> cnt(BUCKET_NUM);
    for (int i = 0; i < len; i++) {
        cnt[arr[i]]++;
    }
    int k = 0;
    for (size_t i = 0; i < BUCKET_NUM; i++) {
        while (cnt[i]--) {
            arr[k++] = i;
        }
    }
}

int main(int argc, char const* argv []) {


    srand((unsigned)time(NULL));
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 100;
    }
    printf("before sort: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    counting_sort(arr, 10);
    printf("after sort: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}