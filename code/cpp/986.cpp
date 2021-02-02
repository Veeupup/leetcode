#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 两个数组的交集，数组已经有序,而且内部不相交，那么可以直接合并成一个然后寻找比较简单
     * @param  {vector<vector<int>>} firstList  : 
     * @param  {vector<vector<int>>} secondList : 
     * @return {vector<vector<int>>}            : 
     */
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if (firstList.size() == 0 || secondList.size() == 0)
            return {};
        
        vector<vector<int>> res;
        int i = 0, j = 0;
        
        int sz1 = firstList.size(), sz2 = secondList.size();
        while (i < sz1 && j < sz2) {
            int l1 = firstList[i][0], r1 = firstList[i][1];
            int l2 = secondList[j][0], r2 = secondList[j][1];
            if (r2 >= l1 && r1 >= l2)
                res.emplace_back(vector<int> {max(l1, l2), min(r1, r2)});
            
            if (r1 <= r2)
                ++i;
            else
                ++j;
        }
        
        return res;
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}