# Problem

[52. N皇后 II](https://leetcode-cn.com/problems/n-queens-ii/)

# Solution

## 分析和思路

[官方题解](https://leetcode-cn.com/problems/n-queens-ii/solution/nhuang-hou-ii-by-leetcode-solution/)

本题是 DFS，回溯的经典案例，首先使用正常的回溯可以做，然后还有使用 **位运算** 来进行求巧的解法。

## code

1. DFS + 剪枝

```c++
class Solution {
public: 
    int totalNQueens(int n) {
        unordered_set<int> columns, leftDia, rightDia;
        return back_dfs(n, 0, columns, leftDia, rightDia);
    }

    int back_dfs(int n, int row, unordered_set<int>& columns, unordered_set<int>& leftDia, unordered_set<int>& rightDia) {
        if(n == row) {
            return 1;
        }else {
            int count = 0;
            for(int i = 0; i < n; ++i) {
                if (columns.find(i) != columns.end())
                    continue;
                if (leftDia.find(row - i) != leftDia.end())
                    continue;
                if (rightDia.find(row + i) != rightDia.end())
                    continue;
                columns.insert(i);
                leftDia.insert(row - i);
                rightDia.insert(row + i);
                count += back_dfs(n, row + 1, columns, leftDia, rightDia);
                columns.erase(i);
                leftDia.erase(row - i);
                rightDia.erase(row + i);
            }
            return count;
        }
    }
};
```

2. 优化判断条件

```c++
class Solution {
public: 
    void dfs(int row[], int cnt, int& ans, int n) {
        if (cnt == n) {
            ans++;
            return;
        }else {
            for (int i = 0; i < n; i++)
            {
                int j = 0;
                for (j = 0; j < cnt; j++)
                {
                    if (row[j] == i || abs(cnt - j) == abs(row[j] - i))
                        break;
                }
                if (j == cnt) {
                    row[cnt] = i;
                    dfs(row, cnt+1, ans, n);
                }
            }
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        int row[n];
        memset(row, 0, sizeof(row));
        dfs(row, 0, ans, n);
        return ans;
    }
};
```

3. 位运算

```c++
class Solution {
public:
    int totalNQueens(int n) {
        return solve(n, 0, 0, 0, 0);
    }

    int solve(int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            return 1;
        } else {
            int count = 0;
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions & (availablePositions - 1);
                count += solve(n, row + 1, columns | position, (diagonals1 | position) << 1, (diagonals2 | position) >> 1);
            }
            return count;
        }
    }
};

```



