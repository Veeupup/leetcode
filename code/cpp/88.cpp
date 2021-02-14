#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 2. 末尾双指针
        int k = m + n - 1;
        m--;
        n--;
        while ((m >= 0) || (n >= 0)) {
            if (m == -1) {
                nums1[k--] = nums2[n--];
            }
            else if (n == -1) {
                nums1[k--] = nums1[m--];
            }
            else if (nums1[m] >= nums2[n]) {
                nums1[k--] = nums1[m--];
            }
            else {
                nums1[k--] = nums2[n--];
            }
        }


        // 1. 简单归并
        // vector<int> num(m + n);
        // int i = 0, j = 0, k = 0;
        // while (i < m && j < n) {
        //     if (nums1[i] < nums2[j]) {
        //         num[k++] = nums1[i++];
        //     }
        //     else {
        //         num[k++] = nums2[j++];
        //     }
        // }
        // while (i < m) {
        //     num[k++] = nums1[i++];
        // }
        // while (j < n) {
        //     num[k++] = nums2[j++];
        // }
        // nums1 = num;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}