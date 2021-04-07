#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 贪心的思路
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int ans = 0, len = answers.size();
        for (int i = 0; i < len; i++) {
            int cnt = answers[i];
            ans += cnt + 1; // 每个说 cnt 的至少有 cnt + 1 个🐰
            int k = cnt;
            while (k-- && i + 1 < len && answers[i+1] == cnt)
                i++;
        }
        return ans;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}