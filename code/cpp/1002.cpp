#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> minFreq(26, INT_MAX);
        vector<int> freq(26);
        for (const string& word : A)
        {
            fill(freq.begin(), freq.end(), 0);
            for (char ch : word) {
                ++freq[ch-'a'];
            }
            for (int i = 0; i < 26; i++)
            {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < minFreq[i]; j++)
            {
                ans.emplace_back(1, i +'a');
            }
        }
        
        return ans;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> A = {"bella", "label", "roller"};
    vector<string> result = so->commonChars(A);
    for (auto str : result)
        cout << str << " ";
    cout << endl;

    A = {"cool","lock","cook"};
    result = so->commonChars(A);
    for (auto str : result)
        cout << str << " ";
    cout << endl;

    return 0;
}
