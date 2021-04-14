#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 尝试从每个位置出发再回到开始的地方，可以使用环状数组，
    // 暴力思路
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {   // 计算每个位置出发能否到达
            int now_gas = gas[i];   // 保存当前的油箱剩余的油
            int j = 0;
            for (; j < n; j++) {
                int now_pos = (j + i) % n;
                if (now_gas < cost[now_pos])
                    break;  // 当前的油不能到达下一站
                now_gas -= cost[now_pos];   // 消耗油走到下一站
                now_gas += gas[(now_pos + 1) % n];  // 加上油
            }
            if (j == n)
                return i;
        }
        return -1;
    }

    /**
     *  强烈建议这个思路
     *  https://leetcode-cn.com/problems/gas-station/solution/shi-yong-tu-de-si-xiang-fen-xi-gai-wen-ti-by-cyayc/
     */
    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int spare = 0, min_spare = INT_MAX;
        int res = 0;
        for (int i = 0; i < n; i++) {
            spare = spare + gas[i] - cost[i];
            if (spare < min_spare) {
                res = i;
                min_spare = spare;
            }
        }
        return spare < 0 ? -1 : (res + 1) % n;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}