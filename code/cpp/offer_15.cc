#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for (;n;n=n>>1) {
            if (n & 1) {
                sum++;
            }
        }
        return sum;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.hammingWeight(10);
    return 0;
}