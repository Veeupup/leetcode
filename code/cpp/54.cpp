#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 方向 右 下 左 上
     * 应该设定每个方向的边界，每次移动结束修改边界，当某个方向到达边界的时候结束
     *
     * @param  {vector<vector<int>>} matrix :
     * @return {vector<int>}                :
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        vector<int> ans;
        int l_b = 0, r_b = matrix[0].size() - 1, t_b = 0, b_b = matrix.size() - 1;
        int i = 0, j = 0, cnt = 0, total = matrix.size() * matrix[0].size();
        while (1) {
            while (j <= r_b) {
                ans.emplace_back(matrix[i][j++]);
                ++cnt;
            }
            t_b++;
            j--;    // j = r_b+1
            i++;
            if (cnt == total)
                break;
            while (i <= b_b) {
                ans.emplace_back(matrix[i++][j]);
                ++cnt;
            }
            r_b--;
            i--;
            j--;
            if (cnt == total)
                break;
            while (j >= l_b) {
                ans.emplace_back(matrix[i][j--]);
                ++cnt;
            }
            b_b--;
            j++;
            i--;
            if (cnt == total)
                break;
            while (i >= t_b) {
                ans.emplace_back(matrix[i--][j]);
                ++cnt;
            }
            l_b++;
            i++;
            j++;
            if (cnt == total)
                break;
        }
        return ans;
    }
};

int main(int argc, char const* argv []) {
    /**
    * 1     2   3   4
    * 5     6   7   8
    * 9     10  11  12
    * 1     2   3   4
    *
    */

    vector<vector<int>> arr = { {1,2,3,4},{5,6,7,8},{9,10,11,12}, {1,2,3,4} };
    Solution so;
    vector<int> res = so.spiralOrder(arr);
    for (int x : res) {
        cout << x << ", ";
    }
    cout << endl;

    return 0;
}