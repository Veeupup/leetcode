#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> my_map;
        for (int num : nums) {
            my_map[num]++;
        }
        for (auto item : my_map) {
            if (item.second == 1)
                return item.first;
        }
        return 0;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}