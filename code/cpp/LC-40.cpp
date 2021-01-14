#include <bits/stdc++.h>
using namespace std;

/**
* 找出最小的 K 个数，使用小顶堆来进行排序
    建堆的过程 从前往后 下沉每个节点到相应的位置
    对于下标为 n 的数字，左子节点为 2n 右子节点为 2n+1

*/

class Solution {
public:
    // vector<int> getLeastNumbers(vector<int>& arr, int k) {
    //     vector<int> res;
    //     if (k == 0)
    //         return res;
    //     priority_queue<int, vector<int>, greater<int>> iq;
    //     for(auto x : arr) {
    //         iq.push(x);
    //     }
    //     while(k-- && !iq.empty()) {
    //         res.emplace_back(iq.top());
    //         iq.pop();
    //     }
    //     return res;
    // }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (k == 0)
            return res;
        return quickSearch(arr, k, 0, arr.size() - 1);
    }

    vector<int> quickSearch(vector<int>& arr, int k, int start, int end) {
        int idx = partition(arr, start, end);
        if (idx == k) {
            vector<int> res(arr.begin(), arr.begin() + k);
            return res;
        }
        return idx > k ? quickSearch(arr, k, start, end - 1) : quickSearch(arr, k, idx + 1, end);
    }

    int partition(vector<int>& arr, int lo, int hi) {
        int key = arr[lo];
        int i = lo, j = ++hi;
        while (lo < hi) {
            while (++i < j && arr[i] < key);
            while (--j > i && arr[j] > key);
            if (i >= j)
                break;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
        arr[lo] = arr[j];
        arr[j] = key;
        return j - 1;
    }

};

int main() {
    Solution so;
    int arr[] = { 0,1,2,1,7 }, k = 2;
    vector<int> iv(arr, arr + 5);
    auto res = so.getLeastNumbers(iv, 2);
    for (auto x : res) {
        cout << x << endl;
    }


    return 0;
}