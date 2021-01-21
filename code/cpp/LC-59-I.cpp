#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 单调队列
     *
     * @param  {vector<int>} nums :
     * @param  {int} k            :
     * @return {vector<int>}      :
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0)
            return vector<int> {};
        vector<int> res;
        deque<int> dq;
        for (int j = 0, i = 1 - k; j < nums.size(); ++i, ++j) {
            // 如果删除的元素等于单调队列中的最大值，那么删除
            if (i > 0 && dq[0] == nums[i - 1])
                dq.pop_front();
            // 删除所有小于要添加进来的元素
            while (!dq.empty() && dq.back() < nums[j])
                dq.pop_back();
            dq.emplace_back(nums[j]);
            if (i >= 0)
                res.emplace_back(dp[0]);
        }
        return res;
    }
};

int main(int argc, char const* argv []) {

    


    return 0;
}