#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 划分子集，注意不要划分重复的子集
     *
     * @param  {vector<int>} nums     :
     * @return {vector<vector<int>>}  :
     */
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        for (int k = 0; k <= n; k++) {
            dfs(nums, res, path, k, 0);
        }
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int k, int begin) {
        if (k == path.size()) {
            res.push_back(path);
        }
        else {
            for (int i = begin, n = nums.size(); i < n; i++) {
                if (i > begin && nums[i] == nums[i - 1]) {
                    continue;
                }
                path.emplace_back(nums[i]);
                dfs(nums, res, path, k, i + 1);
                path.pop_back();
            }
        }
    }
};

int main(int argc, char const* argv []) {

    vector<int> arr{ 2,2,1 };
    Solution so;
    auto res = so.subsetsWithDup(arr);
    for (auto vec : res) {
        cout << "[";
        for (auto x : vec) {
            cout << x << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}