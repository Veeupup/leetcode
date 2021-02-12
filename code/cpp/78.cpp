#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        vector<vector<int>> res;
        vector<int> path;
        for (int k = 0, n = nums.size(); k <= n; k++) {
            dfs(res, nums, path, n, k, 0);
        }
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& path, int n, int k, int begin) {
        if (path.size() == k) {
            res.emplace_back(path);
        }
        else {
            for (int i = begin; i < n; i++) {
                path.emplace_back(nums[i]);
                dfs(res, nums, path, n, k, i + 1);
                path.pop_back();
            }
        }
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    vector<int> arr{ 1,2,3 };
    auto res = so.subsets(arr);
    for (auto vec : res) {
        printf("[");
        for (int x : vec)
            printf("%d, ", x);
        printf("]\n");
    }

    return 0;
}