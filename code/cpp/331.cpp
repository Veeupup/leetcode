#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int i = 0;
        int n = preorder.length();
        stack<int> sta;
        sta.push(1);
        while (i < n) {
            if (sta.empty()) {
                return false;
            }
            else if (preorder[i] == ',') {
                i++;
                continue;
            }
            else if (preorder[i] == '#') {
                sta.top() -= 1;
                if (sta.top() == 0) {
                    sta.pop();
                }
                ++i;
            }
            else {  // 是数字
                while (i < n && preorder[i] != ',') {
                    i++;
                }
                sta.top() -= 1;
                if (sta.top() == 0) {
                    sta.pop();
                }
                sta.push(2);
            }
        }
        return sta.empty();
    }
};

int main(int argc, char const* argv []) {

    string str = "9,3,4,#,#,1,#,#,#,#,6,#,#";
    Solution so;
    cout << so.isValidSerialization(str) << endl;


    return 0;
}