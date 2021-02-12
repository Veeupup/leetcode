#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string str = string("123456789").substr(0, n);
        do {
            k--;
        } while (k && next_permutation(str.begin(), str.end()));
        return str;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.getPermutation(4, 9) << endl;


    return 0;
}