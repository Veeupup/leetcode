#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<string> result = {beginWord};
        vector<bool> visited(wordList.size(), false);
        if (hasRoute(beginWord, endWord, wordList, visited, result))
        {
            return result;
        }

        return vector<string>{};
    }

private:
    bool canTranslate(string str1, string str2)
    {
        int distance = 0;
        if (str1.size() != str2.size())
            return false;
        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] != str2[i])
                distance++;
        }
        return distance == 1;
    }
    bool hasRoute(string curWord, string endWord, vector<string> &wordList,
                  vector<bool> &visited, vector<string> &result)
    {
        if (curWord == endWord)
            return true;
        for (int i = 0; i < wordList.size(); ++i)
        {
            if (visited[i] || !canTranslate(curWord, wordList[i]))
                continue;
            visited[i] = true;
            result.push_back(wordList[i]);
            if (hasRoute(wordList[i], endWord, wordList, visited, result))
            {
                return true;
            }
            result.pop_back();
            // 如果运行到这一步，意味着无法从i这个点找到路径，所以visited[i]无需改为false.
            // visited[i] = false;
        }
        return false;
    }
};

int main()
{
    Solution *so = new Solution();
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<string> result = so->findLadders(beginWord, endWord, wordList);
    for (string str : result)
    {
        cout << str << "-->";
    }

    return 0;
}
