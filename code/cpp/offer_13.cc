/**
* 两种方式：bfs 与 dfs 记得设置访问数组
*/
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(m, n, k, 0, 0, visited);
        // return bfs(m, n, k, 0, 0);
    }

private:
// 1. bfs
    int bfs(int m, int n, int k, int p, int q) {
        int ans = 1;    // 至少能有 (0, 0) 这个点
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> iq;
        iq.push(pair<int, int>(0, 0));
        visited[p][q] = true;
        while (!iq.empty()) {
            p = iq.front().first;
            q = iq.front().second;
            iq.pop();
            if (canIn(m, n, k, p, q+1, visited)) {   // 右
                visited[p][q + 1] = true;
                ans++; 
                iq.push(pair<int, int>(p, q+1));
            }
            if (canIn(m, n, k, p+1, q, visited)) {   // 下
                visited[p+1][q] = true;
                ans++; 
                iq.push(pair<int, int>(p+1, q));
            }
        }
        return ans;        
    }

    bool canIn(int m, int n, int k, int p, int q, vector<vector<bool>>& visited) {
        if (p < 0 || p >= m || q < 0 || q >= n || visited[p][q])
            return false;
        // 计算数位和
        int sum = 0;
        while (p!=0) {
            sum += p%10;
            p/=10;
        }
        while (q!=0) {
            sum += q%10;
            q/=10;
        }
        return sum <= k;
    }

// 2. dfs
    int dfs(int m, int n, int k, int p, int q, vector<vector<bool>>& visited) {
        if (p < 0 || p >= m || q < 0 || q >= n || visited[p][q])
            return false;
        if (get(p) + get(q) > k)
            return false;
        visited[p][q] = true;
        return 1 + dfs(m, n, k, p+1, q, visited) + dfs(m, n, k, p, q+1, visited);
    }

    int get(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};