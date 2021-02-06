#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 四数之和
     *
     *  四数之和转换为三数之和=》两数之和
     *
     * @param  {vector<int>} nums     :
     * @param  {int} target           :
     * @return {vector<vector<int>>}  :
     */

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int n = nums.size();
        for (int first = 0; first < n; ++first) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            for (int second = first + 1; second < n; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;

                int t_sum = nums[first] + nums[second];
                // 三 四 双指针
                int third = second + 1;
                int fourth = n - 1;
                while (third < fourth) {
                    while (third > second + 1 && third < n && nums[third] == nums[third - 1]) third++;  // 去除重复元素
                    if (third >= fourth)
                        break;
                    int sum = t_sum + nums[third] + nums[fourth];
                    if (sum == target) {
                        res.emplace_back(vector<int> {nums[first], nums[second], nums[third], nums[fourth]});
                        third++;
                    }
                    else if (sum > target)
                        fourth--;
                    else if (sum < target)
                        third++;
                }

                // for (int third = second + 1; third < n; ++third) {
                //     if (third > second + 1 && nums[third] == nums[third - 1])
                //         continue;
                //     while (third < fourth && t_sum + nums[third] + nums[fourth] > target)
                //         --fourth;
                //     if (third == fourth)
                //         break;
                //     int sum = t_sum + nums[third] + nums[fourth];
                //     if (sum == target) {
                //         res.emplace_back(vector<int> {nums[first], nums[second], nums[third], nums[fourth]});
                //     }
                // }
            }
        }
        return res;
    }

};

int main(int argc, char const* argv []) {

    vector<int> arr{ 1, 0, -1, 0, -2, 2 };
    int target = 0;
    Solution so;
    vector<vector<int>> vecs = so.fourSum(arr, target);
    for (vector<int> vec : vecs) {
        for (int x : vec) {
            cout << x << ",";
        }
        cout << endl;
    }

    return 0;
}