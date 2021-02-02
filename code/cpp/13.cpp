#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> nums{
        {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000},
        {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}
    };
    int romanToInt(string s) {
        if (s.size() == 0)
            return 0;
        int idx = 0, n = s.size();
        int res = 0;
        while (idx < n) {
            if (idx + 1 < n && nums.count(s.substr(idx, 2))) {
                res += nums[s.substr(idx, 2)];
                idx += 2;
            }
            else {
                res += nums[s.substr(idx, 1)];
                ++idx;
            }
        }
        return res;
    }

    int romanToInt2(string s) {
        if (s.size() == 0)
            return 0;
        int sum = 0;
        int preNum = nums[s.substr(0, 1)];
        for (int i = 1; i < s.size(); i++) {
            int num = nums[s.substr(i, 1)];
            if (preNum < num)
                sum -= preNum;
            else
                sum += preNum;
            preNum = num;
        }
        sum += preNum;
        return sum;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.romanToInt("IV") << endl;
    cout << so.romanToInt("MCMXCIV") << endl;

    return 0;
}