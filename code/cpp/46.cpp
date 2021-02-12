#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     backtrace(res, nums, 0);
    //     return res;
    // }

    // void backtrace(vector<vector<int>>& res, vector<int>& nums, int n) {
    //     if (n == nums.size()) {
    //         res.emplace_back(nums);
    //         return;
    //     }
    //     for (int i = n; i < nums.size(); ++i) {
    //         swap(nums[n], nums[i]);
    //         backtrace(res, nums, n + 1);
    //         swap(nums[n], nums[i]);
    //     }
    // }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        unordered_set<int> vis;
        backtrace(res, nums, path, vis, 0);
        return res;
    }

    void backtrace(vector<vector<int>>& res, vector<int>& nums, vector<int>& path, unordered_set<int>& vis, int n) {
        if (n == nums.size()) {
            res.push_back(path);
        }
        else {
            for (int x : nums) {
                if (vis.count(x))
                    continue;
                path.emplace_back(x);
                vis.insert(x);
                backtrace(res, nums, path, vis, n + 1);
                vis.erase(x);
                path.pop_back();
            }
        }
    }

    // vector<vector<int>> res;
    // set<int> iset;
    // vector<vector<int>> permute2(vector<int>& nums) {
    //     vector<int> path;
    //     backtrace(nums, path, 0);
    //     return res;
    // }

    // void backtrace(vector<int>& nums, vector<int>& path, int n) {
    //     if (n == nums.size()) {
    //         res.emplace_back(path);
    //         return;
    //     }
    //     for (auto x : nums) {
    //         if (iset.find(x) != iset.end())
    //             continue;
    //         iset.insert(x);
    //         path.emplace_back(x);
    //         backtrace(nums, path, n + 1);
    //         path.pop_back();
    //         iset.erase(x);
    //     }
    // }
};

int main(int argc, char const* argv []) {

    Solution so;
    vector<int> arr{ 1,2,3 };
    auto res = so.permute(arr);
    for (auto vec : res) {
        cout << "[";
        for (int x : vec)
            cout << x << ",";
        cout << "]" << endl;
    }


    return 0;
}