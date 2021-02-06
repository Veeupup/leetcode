#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 字母的组合
     *
     * 对于每一个数字，有多种组合， O(n^2),使用 map<int, string> 来保存每个数字对应的字母
     *
     * 先把所有的元素都列出来，然后循环生成
     *
     * @param  {string} digits   :
     * @return {vector<string>}  :
     */
    unordered_map<int, string> keys{
         {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
        {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
    };

    vector<string> res;
    string tmp;
    vector<string> letterCombinations2(string digits) {
        if (digits.size() == 0)
            return {};
        dfs(0, digits);
        return res;
    }

    void dfs(int depth, string digits) {
        if (depth == digits.size()) {
            res.emplace_back(tmp);
            return;
        }
        int num = digits[depth] - '0';
        for (char ch : keys[num]) {
            tmp.append(string(1, ch));
            dfs(depth + 1, digits);
            tmp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        // 构造循环的元素
        int n = digits.size();
        vector<vector<char>> all_letters(n);
        for (int i = 0; i < n; ++i) {
            int num = digits[i] - '0';
            string words = keys[num];
            for (char word : words) {
                all_letters[i].emplace_back(word);
            }
        }

        vector<string> res;
        string str;
        combinaWords(res, all_letters, 0, str, n);

        return res;
    }

    // 每次遍历增加一层的元素
    void combinaWords(vector<string>& res, vector<vector<char>>& all_letters, int depth, string& str, int n) {
        if (depth == n) {
            res.emplace_back(str);
            return;
        }
        for (char ch : all_letters[depth]) {
            str.append(string(1, ch));
            combinaWords(res, all_letters, depth + 1, str, n);
            str = str.substr(0, str.size() - 1);
        }
    }
};

int main(int argc, char const* argv []) {
    Solution so;
    auto res = so.letterCombinations2("23");
    for (auto str : res) {
        cout << str << ",";
    }
    cout << endl;

    // res = so.letterCombinations("234");
    // for (auto str : res) {
    //     cout << str << ",";
    // }
    // cout << endl;

    return 0;
}