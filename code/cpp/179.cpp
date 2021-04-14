#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 排列数字的顺序，应该从高位开始看每个数字，将每个数字转成字符串
    // 然后从高位开始向低位比较，重心，写比较函数，贪心来找
    // 如果两个数字位数相同，那么从高位开始比较，找到开始数字比较大的那一个
    // 如果数字位数不同，但是前导位置相同，那么应该选比较少的那一个
    // 所以说应该将所有数字来进行排序
    string largestNumber(vector<int>& nums) {
        vector<string> nums_str;
        for (int num : nums)
            nums_str.push_back(to_string(num));
        sort(nums_str.begin(), nums_str.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        string res;
        bool start = true;
        for (string num : nums_str) {
            if (start) {
                if (num == "0")
                    continue;
                else
                    res += num;
                start = false;
            }else {
                res += num;      
            }
        }
        return res.size() > 0 ? res : "0";
    }
};

int main(int argc, char const* argv []) {

    vector<int> arr{ 3,30,34,5,9 };
    Solution so;
    cout << so.largestNumber(arr) << endl;


    return 0;
}