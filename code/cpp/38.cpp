#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 迭代或者递归解决
     */
    string countAndSay(int n) {
        string cur = "1";
        for (int i = 0; i < n - 1; i++) {
            string temp;
            for (int j = 0, len = cur.size(); j < len;) {
                int k = j;
                char count = '1';
                while (j < len - 1 && cur[j + 1] == cur[j]) {
                    count++;
                    j++;
                }
                if (cur[k] == cur[j])
                    j++;
                temp.append(string(1, count));
                temp.append(string(1, cur[k]));
            }
            cur = temp;
        }
        return cur;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    for (int i = 1; i < 10; i++) {
        cout << so.countAndSay(i) << endl;
    }

    return 0;
}