#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return {};
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];
                return a[0] < b[0];
            });

        int left = intervals[0][0];
        int right = intervals[0][1];

        for (int i = 1, len = intervals.size(); i < len; ++i) {
            int nowl = intervals[i][0], nowr = intervals[i][1];
            // 包含在内
            if (nowl >= left && nowr <= right)
                continue;
            // 右边变长，合并
            if (nowl <= right && nowr >= right) {
                right = nowr;
                continue;
            }
            // 新的区间不能合并
            if (nowl > right) {
                res.emplace_back(vector<int> {left, right});
                left = nowl;
                right = nowr;
            }
        }
        res.emplace_back(vector<int> {left, right});
        return res;
    }
};

int main(int argc, char const* argv []) {

    vector<vector<int>> arr{ {1,3},{2,6},{8,10},{15,18} };
    Solution so;
    auto res = so.merge(arr);
    for (auto vec : res) {
        for (int x : vec)
            cout << x << ", ";
        cout << endl;
    }

    return 0;
}