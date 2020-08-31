#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool containsPattern(vector<int> &arr, int m, int k){
        int len = arr.size();
        int show_times = 0;     // 模式出现的次数
        vector<int> temp_patt(m);       // 保存临时的模式数组
        for (int i = 0; i < len; i++){
            
            // 如果当前剩余的元素个数 小于 必须满足的最少元素条件，那么直接返回 false
            if ((len - i) < m * k)
                return false;
            
            // 保存新的数组，进行测试是否满足模式
            for (int j = 0; j < m; j++){
                temp_patt[j] = arr[i+j];
            }

            show_times++;   // 出现 1 次
            // 保存下一个模式可能出现的起始和结束位置
            int next_start = i + m, next_end = i + 2*m - 1;
            while (next_end < len) {  // 保证数组不越界
                int j;
                // 检查下一个可能出现的模式的位置是否和当前模式相同
                for (j = 0; j < m; j++){
                    if(temp_patt[j] != arr[next_start + j])
                        break;
                }
                if (j == m) {   // 完全相同
                    next_start += m;
                    next_end += m;
                    show_times++;
                    if(show_times == k) {
                        return true;
                    }
                }else {     // 和之前的模式不相同
                    break;
                }

            }
            
            show_times = 0; // 当前模式不匹配，恢复成 0    
        }        
        return false;
    }
};

int main()
{
    Solution *so = new Solution();

    vector<int> arr{1,2,4,4,4,4};
    int m = 1, k = 3;
    cout << so->containsPattern(arr, m, k) << endl;

    arr = {1,2,1,2,1,1,1,3};
    m = 2, k = 2;
    cout << so->containsPattern(arr, m, k) << endl;

    arr = {1,2,1,2,1,3};
    m = 2, k = 3;
    cout << so->containsPattern(arr, m, k) << endl;

    arr = {1,2,3,1,2};
    m = 2, k = 2;
    cout << so->containsPattern(arr, m, k) << endl;

    arr = {2,2,2,2};
    m = 2, k = 3;
    cout << so->containsPattern(arr, m, k) << endl;

    arr = {1, 2};
    m = 1, k = 2;
    cout << so->containsPattern(arr, m, k) << endl;

    return 0;
}
