#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSwapValues(vector<int> &array1, vector<int> &array2)
    {
        set<int> tableA ,tableB;
        int sumA = 0, sumB = 0;
        for (int i : array1) {
            sumA += i;
            tableA.insert(i);
        }
            
        for (int i : array2) {
            sumB += i;
            tableB.insert(i);
        }  
        int dis = sumA - sumB;
        if (dis % 2 != 0)
            return {};
        dis /= 2; // 如果 sumA > sumB,那么 dis > 0,需要在 A 中找到较大的送给 B
        for (int a : tableA)
        {
            // 计算出 需要的 b 的值, a - b = dis, b = a - dis
            if (tableB.find(a - dis) != tableB.end()) {
                return {a, a - dis};
            }
        }
        return {};
    }
};

int main()
{
    Solution *so = new Solution();

    vector<int> arr1{4, 1, 2, 1, 1, 2}, arr2{3, 6, 3, 3};
    vector<int> result = so->findSwapValues(arr1, arr2);

    for (auto i : result)
    {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
