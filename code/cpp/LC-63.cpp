#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 计算买卖股票能赚到的最大值
     * 1. 暴力遍历 O(n^2)
     * 2. 单调栈，搞一个单调递增的栈，或者是队列也行，只保存单调递增的
     * 输入: [7,1,5,3,6,4]
     * 从前往后遍历，记录最小值，
     * @param  {vector<int>} prices : 
     * @return {int}                : 
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int min_val = prices[0], res = 0;
        for (auto x : prices) {
            if (x > min_val)
                res = max(res, x - min_val);
            else
                min_val = x;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}