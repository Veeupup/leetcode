#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 输出和为 target 的连续正整数数列
     * 设 第一个数字为 x，一共有 n 个数字，则和为 (x + x + n - 1) * n / 2 = (2x+n-1)n/2
     * 从 1～n/2
     * @param  {int} target           :
     * @return {vector<vector<int>>}  :
     */
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        int sum = 0;
        int l = 1, r = 1;
        // 左闭右开区间，从 1 1 开始
        while (l <= target / 2) {
            if (sum < target) {
                sum += r++;
            }
                sum -= l++;
            }
            else {
                tmp.clear();
                for (int i = l; i < r; i++)
                    tmp.emplace_back(i);
                res.emplace_back(tmp);
                sum -= l++;
            }
        }
        return res;
        // vector<vector<int>> res;
        // vector<int> tmp;
        // int sum = 0;
        // for (int i = 1, end = target / 2; i <= end; i++) {
        //     for (int j = i;; j++) {
        //         sum += j;
        //         if (sum > target) {
        //             sum = 0;
        //             break;
        //         }
        //         else if (sum == target) {
        //             tmp.clear();
        //             for (int k = i; k <= j; k++)
        //                 tmp.emplace_back(k);
        //             res.emplace_back(tmp);
        //             sum = 0;
        //             break;
        //         }
        //     }
        // }
        // return res;
    }
};

int main(int argc, char** argv) {

    if (argc < 1) {
        cout << "usage: ./a.out 15" << endl;
        return 0;
    }

    int x = atoi(argv[1]);

    Solution so;
    auto res = so.findContinuousSequence(x);
    for (auto iv : res) {
        for (auto x : iv) {
            cout << x << ",";
        }
        cout << endl;
    }


    return 0;
}