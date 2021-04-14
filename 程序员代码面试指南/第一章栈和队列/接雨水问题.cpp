#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    int row[m];
    memset(row, 0, m*sizeof(int));
    int max_square = 0;    // 返回的最大面积
    
    for(int i=0; i<n; i++){
        // 计算当前行的统计直方图的值, 0 或 1
        for(int j=0; j<m; j++){
            row[j] = arr[i][j]==0 ? 0 : row[j]+1;
        }

        stack<int> stk;
        for(int k=0; k<m; k++){
            while(!stk.empty() && row[stk.top()]>=row[k]){
                int index = stk.top();
                stk.pop();
                int left_index = stk.empty() ? -1: stk.top();
                int tmp_square = (k-left_index-1)*row[index];
                // 记录最大面积
                if(tmp_square > max_square)
                    max_square = tmp_square;
            }
            stk.push(k); // 加入新元素
        }
        // 清空栈内元素
        while(!stk.empty()){
            int index = stk.top();
            stk.pop();
            int left_index = stk.empty() ? -1 : stk.top();
            int tmp_square = (m-left_index-1)*row[index];
            // 记录最大面积
            if(tmp_square > max_square)
                max_square = tmp_square;
        }
        
    }
    cout<< max_square;
    return 0;
}