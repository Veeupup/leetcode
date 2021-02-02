#include <bits/stdc++.h>
using namespace std;

/**
* I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Solution {
public:
    unordered_map<int, string> nums{
        {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"},
        {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}
    };
    /**
     * 应该使用贪心匹配
     * @param  {int} num :
     * @return {string}  :
     */
    string intToRoman(int num) {
        string res;

        int thousand_num = num / 1000;  // 千位
        while (thousand_num--) {
            res.append(nums[1000]);
        }
        num %= 1000;    // 除去千位

        int hundred_num = num / 100;
        if (hundred_num == 9) {
            res.append(nums[900]);
        }
        else if (hundred_num == 4) {
            res.append(nums[400]);
        }
        else if (hundred_num < 4) {
            while (hundred_num--)
                res.append(nums[100]);
        }
        else if (hundred_num >= 5) {
            res.append(nums[500]);
            hundred_num -= 5;
            while (hundred_num--)
                res.append(nums[100]);
        }
        num %= 100;

        int shi_num = num / 10;
        if (shi_num == 9) {
            res.append(nums[90]);
        }
        else if (shi_num == 4) {
            res.append(nums[40]);
        }
        else if (shi_num < 4) {
            while (shi_num--)
                res.append(nums[10]);
        }
        else if (shi_num >= 5) {
            res.append(nums[50]);
            shi_num -= 5;
            while (shi_num--)
                res.append(nums[10]);
        }
        num %= 10;

        if (num == 9) {
            res.append(nums[9]);
        }
        else if (num == 4) {
            res.append(nums[4]);
        }
        else if (num < 4) {
            while (num--)
                res.append(nums[1]);
        }
        else if (num >= 5) {
            res.append(nums[5]);
            num -= 5;
            while (num--)
                res.append(nums[1]);
        }

        return res;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    for (int i = 1; i < 199; i++)
    {
        cout << so.intToRoman(i) << endl;
    }
    
    


    return 0;
}