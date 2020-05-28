#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /**
 * 暴力法
 * 使用前缀和来减少计算次数
*/
public:
    int subarraysDivByK_1(vector<int> &A, int K)
    {
        int len = A.size();
        // 记录前 N 个数字之和，之后的计算就只需要做一次减法
        vector<int> sumToN;
        sumToN.push_back(0);
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += A[i];
            sumToN.push_back(sum);
        }
        int x = 0, ans = 0;
        // 此时的区间为 左闭右开 [1, 3) 指包含，1,2 两个元素
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j <= len; j++)
            {
                x = sumToN[j] - sumToN[i];
                if (x % K == 0)
                    ans++;
            }
        }
        return ans;
    }

    /**
 *  利用同余定理
 *  (a - b) mod K = a mod K - b mod K 
 *  
*/
    int subarraysDivByK(vector<int> &A, int K)
    {
         // 如果只有一个元素刚好能够被整除
        unordered_map<int, int> record = {{0, 1}}; 
        int sum = 0, ans = 0, key = -1;
        for (int elem : A)
        {
            sum += elem;
            // 有可能为负数
            key = (sum % K + K) % K;
            if(record.count(key))
                ans += record[key];
            record[key]++;
        }
        return ans;
    }
};

int main()
{
    Solution *s = new Solution();
    int arr[] = {4, 5, 0, -2, -3, 1};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    cout << s->subarraysDivByK(vec, 5) << endl;
    return 0;
}