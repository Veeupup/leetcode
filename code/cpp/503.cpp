#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        stack<int> sta;
        vector<int> res(n);
        for (int i = 2 * n - 1; i >= 0; i--) {
            int num = nums[i];
            while (!sta.empty() && num >= sta.top()) {
                sta.pop();
            }
            if (sta.empty()) {
                if (i < n)
                    res[i] = -1;
            }
            else {
                if (i < n)
                    res[i] = sta.top();
            }
            sta.push(num);
        }
        return res;
    }

    vector<int> nextGreaterElements2(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;
    }

};

int main(int argc, char const* argv []) {

    Solution so;
    vector<int> nums{ 1, 2, 1 };
    auto res = so.nextGreaterElements2(nums);
    for (int i = 0; i < 3; i++) {
        cout << res[i] << ", ";
    }
    cout << endl;


    return 0;
}