#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, res, path, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& path, int target, int begin) {
        if (target == 0) {
            res.emplace_back(path);
        }
        else {
            for (int i = begin, len = candidates.size(); i < len; i++) {
                if (i > begin && candidates[i] == candidates[i - 1])
                    continue;   // 消除同级相同的元素，但是下一层相同的元素仍然可以使用
                if (target - candidates[i] < 0)
                    break;
                path.emplace_back(candidates[i]);
                dfs(candidates, res, path, target - candidates[i], i + 1);
                path.pop_back();
            }
        }
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    vector<int> candidates{ 10,1,2,7,6,1,5 };
    int target = 8;
    auto res = so.combinationSum2(candidates, target);
    for (auto vec : res) {
        cout << "[";
        for (int x : vec) {
            cout << x << ",";
        }
        cout << "]" << endl;
    }


    return 0;
}