#include <bits/stdc++.h>
using namespace std;

void shell_sort(int arr [], int len) {
    int x = 0;
    for (int gap = len / 2; gap > 0; gap /= 2) {
        for (int j = gap; j < len; j++) {
            int tmp = arr[j];
            int pre;
            for (pre = j - gap; pre >= 0; pre -= gap) {
                if (arr[pre] > tmp) {
                    arr[pre + gap] = arr[pre];
                }
                else {
                    break;
                }
            }
            arr[pre + gap] = tmp;
        }
        printf("%d 次排序后: ", ++x);
        for (int i = 0; i < len; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
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
    shell_sort(arr, 10);
    printf("after sort: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}