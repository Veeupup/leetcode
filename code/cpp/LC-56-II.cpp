#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i += 3) {
            if (nums[i] != nums[i + 2])
                return nums[i];
        }
        return nums.back();
        //     map<int, int> imap;
        //     for (auto x : nums) {
        //         if (imap.find(x) == imap.end())
        //             imap[x] = 1;
        //         else {
        //             ++imap[x];
        //             if (imap[x] == 3)
        //                 imap.erase(x);
        //         }
        //     }
        //     auto it = imap.begin();
        //     return it->first;
    }
};

int main() {




    return 0;
}