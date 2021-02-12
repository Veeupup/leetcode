#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (carry == 0)
                break;
            int num = digits[i] + carry;
            if (num == 10) {
                digits[i] = 0;
                carry = 1;
            }
            else {
                digits[i] += 1;
            }
        }
        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}