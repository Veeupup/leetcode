#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 移除元素，原地移除，每次删除都需要将之后的元素移动到前面
     * @param  {vector<int>} nums :
     * @param  {int} val          :
     * @return {int}              :
     */
    int removeElement(vector<int>& nums, int val) {
        int idx = 0, len = nums.size();
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (nums[i] == val) {   // 将之后的元素移动到前面
                for (int j = i + 1; j < len; j++) {
                    nums[j - 1] = nums[j];
                }
                --len;
            }
        }
        return len;
    }

    int removeElement2(vector<int>& nums, int val) {
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                n--;
            }
            else {
                i++;
            }
        }
        return i;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}