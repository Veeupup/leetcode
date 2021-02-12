#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 典型 DFS
     * @param  {int} n                :
     * @param  {int} k                :
     * @return {vector<vector<int>>}  :
     */
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, n, k, 1);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& path, int n, int k, int begin) {
        if (path.size() == k) {
            res.emplace_back(path);
        }
        else {
            for (int i = begin; i <= n; i++) {
                path.emplace_back(i);
                dfs(res, path, n, k, i + 1);
                path.pop_back();
            }
        }
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    auto res = so.combine(4, 3);
    for (auto vec : res) {
        printf("[");
        for (int x : vec)
            printf("%d, ", x);
        printf("]\n");
    }

    return 0;
}