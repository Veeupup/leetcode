#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 两个有序数组，归并排序之后找中位数即可
     * @param  {vector<int>} nums1 : 
     * @param  {vector<int>} nums2 : 
     * @return {double}            : 
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        vector<double> num(len);
        int i = 0, j = 0, k = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                num[k] = nums1[i++];
            else
                num[k] = nums2[j++];
            ++k;
        }
        while (i < nums1.size())
            num[k++] = nums1[i++];
        while (j < nums2.size())
            num[k++] = nums2[j++];
        if (len & 1)
            return num [len / 2];
        return (num[len / 2 - 1] + num[len / 2]) / 2;
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}