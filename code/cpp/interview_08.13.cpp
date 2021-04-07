#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 直接贪心？看来不行，可能有很多种组合
    // 可以试试 dp，从小箱子开始 O(n^2)，每次都得和前面的比较，如果是 dfs 的话，

    int pileBox(vector<vector<int>>& box) {
        int len = box.size();
        if (len <= 1)
            return 1;
        sort(box.begin(), box.end(), [](vector<int>& v1, vector<int>& v2) {
            if (v1[0] == v2[0]) {
                if (v1[1] == v2[1]) {
                    return v1[2] < v2[2];
                }
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        });
        vector<int> dp(len);    // dp[i] 代表第 i 个箱子能达到的最大高度
        for (int i = 0; i < len; i++) {
            dp[i] = box[i][2];
        }
        for (int i = 1; i < len; i++) {
            int x_box_w = box[i][0];
            int x_box_d = box[i][1];
            int x_box_h = box[i][2];
            for (int j = 0; j < i; j++) {   // 只可能在比自己小的里面找
                if (box[j][0] < x_box_w && box[j][1] < x_box_d && box[j][2] < x_box_h) {
                    int now_height = dp[j] + x_box_h;
                    dp[i] = max(dp[i], now_height);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}