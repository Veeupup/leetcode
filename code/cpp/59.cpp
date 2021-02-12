#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0)
            return {};
        vector<vector<int>> ans(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int cnt = 1;
        while (true) {
            for (int i = left; i <= right; i++)
                ans[top][i] = cnt++;
            if (++top > bottom)
                break;
            for (int i = top; i <= bottom; i++)
                ans[i][right] = cnt++;
            if (--right < left)
                break;
            for (int i = right; i >= left; i--)
                ans[bottom][i] = cnt++;
            if (--bottom < top)
                break;
            for (int i = bottom; i >= top; i--)
                ans[i][left] = cnt++;
            if (++left > right)
                break;
        }
        return ans;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    auto res = so.generateMatrix(4);
    for (auto vec : res) {
        for (int x : vec)
            printf("%d\t", x);
        printf("\n");
    }


    return 0;
}