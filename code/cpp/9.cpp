#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long y = x;
        long long reverse = 0;
        while (y) {
            reverse = reverse * 10 + y % 10;
            y /= 10;
        }
        return reverse == x;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}