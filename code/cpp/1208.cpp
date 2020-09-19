#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int length = s.size();
        int left = 0, right = 0;    // 保存游标
        int nowCost = 0, ans = 0;    // 保存已经花费的距离

        while (right < length){   // 移动右边的窗口位置
            nowCost += abs(s[right] - t[right]);

            // 如果窗口太大，移动左边窗口的位置
            while (nowCost > maxCost){   
                nowCost -= abs(s[left] - t[left]);
                left++;
            }
            right++;
            ans = max(ans, right - left);
        }
        
        return ans;
    }
};

int main() {
    Solution *so = new Solution();

    string s = "abcd", t = "bcdf";
    int cost = 3;
    cout << so->equalSubstring(s, t, cost) << endl;

    t = "cdef";
    cout << so->equalSubstring(s, t, cost) << endl;

    t = "acde";
    cost = 0;
    cout << so->equalSubstring(s, t, cost) << endl;

    return 0;
}
