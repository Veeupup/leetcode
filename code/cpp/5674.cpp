#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
    *   归并排序
    */
    string largestMerge(string word1, string word2) {
        string merge;
        int i = 0, j = 0;
        int len1 = word1.size(), len2 = word2.size();
        while (i < word1.size() && j < word2.size()) {
            if (word1.substr(i) > word2.substr(j))
                merge += word1[i++];
            else
                merge += word2[j++];
        }
        if (i < len1)
            merge += word1.substr(i);
        if (j < len2)
            merge += word2.substr(j);

        return merge;
    }
};

int main(int argc, char const* argv []) {

    Solution so;
    cout << so.largestMerge("cabaa", "bcaaa") << endl;

    return 0;
}