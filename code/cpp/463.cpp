#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        int columns = grid.size(), rows = grid[0].size();
        queue<pair<int, int>> land; // BFS 访问的列表
        vector<vector<bool>> visited(columns, vector<bool>(rows, false));  // 是否访问过

        // 找到第一块陆地
        int posX = 0, posY = 0;
        bool leave = false;
        for (int i = 0; i < columns; ++i) {
            for (int j = 0; j < rows; ++j) {
                if (grid[i][j]) {
                    posX = i;
                    posY = j;
                    leave = true;
                    break;
                }
            }
            if (leave) break;
        }

        // 开始 BFS
        int ans = 0;
        land.push({posX, posY});
        while(!land.empty()) {
            pair<int, int> nowPos = land.front();
            land.pop();
            posX = nowPos.first, posY = nowPos.second;
            visited[posX][posY] = true; 

            int maxLen = 4;
            // 上方
            if (posX - 1 >= 0 && grid[posX - 1][posY]) {   // 上方存在 1
                maxLen--;   // 边长减一
                if (!visited[posX - 1][posY])
                    land.push({ posX - 1, posY});
            }

            // 下方
            if (posX + 1 < columns && grid[posX + 1][posY]) {   // 上方存在 1
                maxLen--;   // 边长减一
                if (!visited[posX+1][posY])
                    land.push({ posX + 1, posY});
            }
            
            // 左方
            if (posY - 1 >= 0 && grid[posX][posY - 1]) {   // 上方存在 1
                maxLen--;   // 边长减一
                if (!visited[posX][posY - 1])
                    land.push({ posX, posY - 1});
            }

            // 右方
            if (posY + 1 < rows && grid[posX][posY + 1]) {   // 上方存在 1
                maxLen--;   // 边长减一
                if (!visited[posX][posY + 1])
                    land.push({ posX, posY + 1});
            }

            ans += maxLen;
        }

        return ans;
    }
};

int main()
{ 
    Solution s;
    vector<vector<int>> vec = {{0,1,0,0},
                                {1,1,1,0},
                                {0,1,0,0},
                                {1,1,0,0}};

    vec = {{1, 1}, {1, 1}};
    cout << s.islandPerimeter(vec) << endl;
    

    return 0;
}