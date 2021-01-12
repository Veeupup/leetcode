#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        this->n = n;
        char str[n+1];
        dfs(0, str, res);
        return res;
    }

private:
    int n;
    char nums[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    void dfs(int x, char* str, vector<int>& res) {
        if (x == n) {
            res.emplace_back(atoi(str));
            return;
        }else {
            for (int i = 0; i < 10; i++) {
                str[x] = nums[i];
                dfs(x+1, str, res);
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> res = s.printNumbers(2);
    cout << res.size() << endl;
    for (auto x : res) {
        cout << x << ", ";
    }
    return 0;
}