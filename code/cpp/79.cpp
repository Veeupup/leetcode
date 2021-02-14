#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 贪心搜索
     *  每次找到能够继续走的地方就继续走
     *
     *
     * @param  {vector<vector<char>>} board :
     * @param  {string} word                :
     * @return {bool}                       :
     */
    int m, n;
    int directions[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        string path;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, vis, word, path, i, j))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, const string& word, string& path, int row, int col) {
        char tmp = board[row][col];
        if (word[path.size()] == tmp) {
            vis[row][col] = true;
            path.push_back(tmp);

            if (path == word)
                return true;

            for (int i = 0; i < 4; i++) {
                int nextRow = row + directions[i][0];
                int nextCol = col + directions[i][1];
                if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && vis[nextRow][nextCol] == false) {
                    if (dfs(board, vis, word, path, nextRow, nextCol))
                        return true;
                }
            }

            vis[row][col] = false;
            path.pop_back();
        }
        return false;
    }
};

int main(int argc, char const* argv []) {

    vector<vector<char>> board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'} };

    Solution so;
    cout << so.exist(board, "ABCCED") << endl;
    cout << so.exist(board, "SEE") << endl;
    cout << so.exist(board, "ABCB") << endl;
    cout << so.exist(board, "ASAD") << endl;


    return 0;
}