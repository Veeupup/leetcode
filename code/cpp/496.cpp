#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextBig;
        stack<int> sta;
        // 构建单调栈
        for (auto val : nums2)
        {
            while(!sta.empty() && val > sta.top()) {
                nextBig[sta.top()] = val;
                sta.pop();
            }
            sta.emplace(val);
        }
        // 如果栈中还有元素,那么说明没有下一个更大的元素
        while (!sta.empty())
        {
            nextBig[sta.top()] = -1;
            sta.pop();
        }

        vector<int> result;
        for (auto val : nums1)
            result.emplace_back(nextBig[val]);
        
        return result;
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    vector<int> result;

    result = so->nextGreaterElement(nums1, nums2);
    for(auto val : result) {
        cout << val << " ";
    }
    cout << endl;

    nums1 = {2, 4}, nums2 = {1, 2, 3, 4};
    result = so->nextGreaterElement(nums1, nums2);
    for(auto val : result) {
        cout << val << " ";
    }
    cout << endl;

    nums1 = {1,3,5,2,4}, nums2 = {6,5,4,3,2,1,7};
    result = so->nextGreaterElement(nums1, nums2);
    for(auto val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
