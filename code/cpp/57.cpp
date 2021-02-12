#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 思路1 直接合并区间
     *
     * 思路2
     * 找到第一个有交集的区间进行合并，然后不断合并
     * 没有交集：1.
     *
     * @param  {vector<vector<int>>} intervals :
     * @param  {vector<int>} newInterval       :
     * @return {vector<vector<int>>}           :
     */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        vector<vector<int>> res;
        int idx = 0;
        // 左边相离的区间放入
        while (idx < len && intervals[idx][1] < newInterval[0]) {
            res.emplace_back(intervals[idx++]);
        }
        // 合并
        while (idx < len && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }
        res.emplace_back(newInterval);
        while (idx < len) {
            res.emplace_back(intervals[idx++]);
        }
        return res;
    }
};

int main(int argc, char const* argv []) {

    vector<vector<int>>  arr{ {1,5} };
    vector<int> newInterval{ 2,7 };
    Solution so;
    auto res = so.insert(arr, newInterval);
    for (auto vec : res) {
        cout << "[";
        for (int x : vec) {
            cout << x << "-";
        }
        cout << "]";
    }

    return 0;
}