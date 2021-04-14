#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 比较版本号
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int idx1 = 0, idx2 = 0;
        int v1, v2;
        while (idx1 < n1 || idx2 < n2) {
            if (idx1 >= n1) 
                v1 = 0;
            else {
                int pos1 = version1.find(".", idx1);
                v1 = pos1 == -1 ? stoi(version1.substr(idx1)) : stoi(version1.substr(idx1, pos1 - idx1));
                idx1 = pos1 == -1 ? n1 : pos1 + 1;
            }

            if (idx2 >= n2)
                v2 = 0;
            else {
                int pos2 = version2.find(".", idx2);
                v2 = pos2 == -1 ? stoi(version2.substr(idx2)) : stoi(version2.substr(idx2, pos2 - idx2));
                idx2 = pos2 == -1 ? n2 : pos2 + 1;
            }
            if (v1 < v2) {
                return -1;
            }else if (v1 > v2) {
                return 1;
            }
        }
        return 0;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}