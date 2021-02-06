#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 使用单调栈来保存每个点之后的第一个最高的位置
     * @param  {vector<int>} height :
     * @return {int}                :
     */
    int trap(vector<int>& height) {
        
        
    }
    
    // 暴力法，寻找每个柱子之后能够到达的最高的高度
    int trap1(vector<int>& height) {
        int ans = 0;
        for (int i = 1, len = height.size(); i < len; ++i) {
            int left_max = 0, right_max = 0;
            for (int j = i; j >= 0; --j) {
                left_max = max(left_max, height[j]);
            }
            for (int j = i; j < len; ++j) {
                right_max = max(right_max, height[j]);
            }
            ans += min(left_max, right_max) - height[i];
        }
        return ans;
    }

    // 动态法，首先保存好每个值左边右边最高的值
    int trap2(vector<int>& height) {
        int len = height.size();
        vector<int> left_max(height.size());
        vector<int> right_max(height.size());
        left_max[0] = height[0];
        for (int i = 1; i < len; ++i) {
            left_max[i] = max(left_max[i-1], height[i]);
        }
        right_max[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; --i) {
            right_max[i] = max(height[i], right_max[i+1]);
        }
        int ans = 0;
        for (int i = 1; i < len - 1; ++i) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
    
    int trap3(vector<int>& height) {
        stack<int> sta;
        int ans = 0;
        int cur = 0, len = height.size();
        while (cur < len) {
            while (!sta.empty() && height[cur] > height[sta.top()]) {
                int top = sta.top();
                sta.pop();
                if (sta.empty())
                    break;
                int dis = cur - sta.top() - 1;
                int now_height = min(height[cur], height[sta.top()]) - height[cur];
                ans += now_height * dis;
            }
            sta.push(cur++);
        }
        return ans;
    } 
};

int main(int argc, char const* argv []) {

    Solution so;
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    so.trap(height);


    return 0;
}