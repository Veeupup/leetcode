#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
            });

        int left = intervals[0][0];
        int right = intervals[0][1];
        int res = 1;

        for (int i = 1, len = intervals.size(); i < len; i++) {
            int nowl = intervals[i][0];
            int nowr = intervals[i][1];

            if (nowl > right) {
                left = nowl;
                right = nowr;
                continue;
            }   // 当前区间在之前的右边

            if (nowl >= left && nowr <= right) {
                ++res;
                continue;
            } // 被包含在内

            right = nowr;
        }

        return res;
    }
};

int main(int argc, char const* argv []) {

    vector<vector<int>> arr{ {1,4},{3,6},{2,8} };
    Solution so;
    cout << so.removeCoveredIntervals(arr) << endl;

    return 0;
}