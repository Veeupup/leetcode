#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) {
            return;
        }
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }                
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
            
        }
    }
    
    /**
     * 思路: 类似图的遍历 BFS
     *  找到一个 O 然后就从这个 O 开始 BFS，直到找到所有相连的 O，如果某个 O 处在
     *  边界上，那么说明这个区域不能被包围，如果BFS结束时仍然没有出现边界上的 O，那
     *  么说明这个区域内的 O 都可以被填充
     *      需要设置： vis，访问数组    qu，BFS     flag，是否出现了边界的 O
     *              set<pair<int, int>> 记录所有BFS经过的节点
     * 如果已经出现的边界的 O，那么仍然需要继续 BFS 下去
     * 如果遍历的时候发现 O 已经被访问过，那么就不需要开始 BFS
     * @param  {vector<vector<char>>} board : 
     */
    void solve2(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0)
            return;
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> qu;   // BFS
        bool flag = false;  // 是否出现了边界的 O
        set<pair<int, int>> points;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    // 现在是一个没有访问过的 O, board[i][j] == 'O' && vis[i][j] == 0
                    qu.push({i,j});
                    while (!qu.empty()) {
                        auto now = qu.front();
                        qu.pop();
                        int x = now.first, y = now.second;
                        vis[x][y] = 1;
                        points.insert({x, y});
                        if (flag || x == 0 || x == m - 1 || y == 0 || y == n - 1)
                            flag = true;
                        if (x - 1 >= 0 && board[x-1][y] == 'O' && vis[x-1][y] == 0)
                            qu.push({x-1, y});  // 上
                        if (y + 1 < n && board[x][y+1] == 'O' && vis[x][y+1] == 0)
                            qu.push({x, y+1});  // 右
                        if (x + 1 < m && board[x+1][y] == 'O' && vis[x+1][y] == 0)
                            qu.push({x+1, y});
                        if (y - 1 >= 0 && board[x][y-1] == 'O' && vis[x][y-1] == 0)
                            qu.push({x, y-1});
                    }
                    if (!flag) {
                        for (auto now : points) {
                            board[now.first][now.second] = 'X';
                        }
                    }
                    points.clear();
                    flag = false;
                }
            }
        }
    }
};

int main(int argc, char const* argv []) {

    vector<vector<char>> board {
                {'X','X','X','X'},
                {'X','O','O','X'},
                {'X','X','O','X'},
                {'X','O','X','X'},
    };
    //     vector<vector<char>> board {
    //             {'O','O','O'},
    //             {'O','O','O'},
    //             {'O','O','O'},
    // };
    Solution so;
    so.solve(board);
    for (auto vec : board)
    {
        for (char ch : vec)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
    

    return 0;
}