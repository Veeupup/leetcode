#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 回溯 + 剪枝
     * 剪枝需要去除掉重复的解答
     * 2 2 3 和 2 3 2 是同样的答案
     *
     * @param  {vector<int>} candidates :
     * @param  {int} target             :
     * @return {vector<vector<int>>}    :
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, res, path, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& path, int target, int depth) {
        if (target == 0) {
            res.emplace_back(path);
        }
        else {
            for (int i = depth; i < candidates.size(); i++) {
                if (target - candidates[i] < 0)
                    break;
                path.emplace_back(candidates[i]);
                dfs(candidates, res, path, target - candidates[i], i);
                path.pop_back();
            }
        }
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    vector<int> arr{ 2, 3, 6, 7 };
    int target = 7;
    auto res = so.combinationSum(arr, target);
    for (auto vec : res) {
        cout << "[";
        for (int x : vec) {
            cout << x << ",";
        }
        cout << "]" << endl;
    }


    return 0;
}