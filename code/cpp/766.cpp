#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.size() <= 1 || matrix[0].size() == 1)
            return true;
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] != matrix[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution *so = new Solution();

    vector<vector<int>> arr{
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}};
    cout << so->isToeplitzMatrix(arr) << endl;

    return 0;
}
