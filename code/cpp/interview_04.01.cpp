#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 是否有通路，使用 DFS
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<bool> visited(n, false);
        map<int, set<int>> edges;
        for (const vector<int>& edge : graph) {
            edges[edge[0]].insert(edge[1]);
        }
        return dfs(edges, visited, start, target);
    }

    bool dfs(map<int, set<int>>& edges, vector<bool>& visited, int start, int target) {
        if (start == target) {
            return true;
        }
        visited[start] = true;
        for (const auto& next : edges[start]) {
            if (!visited[next] && dfs(edges, visited, next, target))
                return true;
        }
        return false;
    }
};

class Solution2 {
public:
    // 是否有通路，直接使用并查集
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<int> parent(n);
        vector<int> height(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (const auto& vec : graph) {
            connect(vec[0], vec[1], parent, height);
        }

        int father_start = findFather(start, parent);
        int father_end = findFather(target, parent);
        return father_start == father_end;
    }

    void connect(int x, int y, vector<int>& parent, vector<int>& height) {
        x = findFather(x, parent);
        y = findFather(y, parent);
        if (x != y) {
            if (height[x] < height[y]) {
                parent[x] = y;
            }
            else if (height[x] > height[y]) {
                parent[y] = x;
            }
            else {
                parent[x] = y;
                height[y]++;
            }
        }
    }

    int findFather(int x, vector<int>& parent) {
        while (parent[x] != x) {
            x = parent[x];
        }
        return x;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    vector<vector<int>> graph{ {0, 1}, {1, 2}, {1, 3}, {1, 10}, {1, 11}, {1, 4}, {2, 4}, {2, 6}, {2, 9}, {2, 10}, {2, 4}, {2, 5}, {2, 10}, {3, 7}, {3, 7}, {4, 5}, {4, 11}, {4, 11}, {4, 10}, {5, 7}, {5, 10}, {6, 8}, {7, 11}, {8, 10} };
    int start = 2, target = 3;
    int n = 12;
    cout << so.findWhetherExistsPath(12, graph, start, target);


    return 0;
}