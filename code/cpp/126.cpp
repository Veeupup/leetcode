#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int INF = 1 << 20;
    unordered_map<string, int> wordId;
    vector<string> idWord;
    vector<vector<int>> edges;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int id = 0;
        for (const string& word : wordList) {
            if (!wordId.count(word)) {
                wordId[word] = id++;
                idWord.push_back(word);
            }
        }
        if (!wordId.count(endWord)) {
            return {};
        }
        if (!wordId.count(beginWord)) {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }
        // 构建边之间的关系
        int n = wordId.size();
        edges.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
            {
                if (transform_check(idWord[i], idWord[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        
        const int dest = wordId[endWord];
        queue<vector<int>> q;
        vector<vector<string>> ans;
        vector<int> cost(id, INF);
        cost[wordId[beginWord]] = 0;
        q.push(vector<int>{wordId[beginWord]});
        while (!q.empty()) {
            vector<int> now = q.front();
            q.pop();
            int last = now.back();
            if (last == dest) {
                vector<string> tmp;
                for (int idx : now) {
                    tmp.push_back(idWord[idx]);
                }
                ans.push_back(tmp);
            }            
            else {
                for (int i = 0; i < edges[last].size(); i++)
                {
                    int to = edges[last][i];
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return ans;
        
    }

    bool transform_check(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;
        int diff = 0;
        for (int i = 0; i < word1.size() && diff < 2; i++)
        {
            if (word1[i] != word2[i])
                diff++;
        }
        return diff == 1;
    }

    
    /**
     *  思路有问题，要找最短路径，那么就应该用 BFS，如果要找到所有的路径，那么可以使用 DFS
     * 典型 DFS
     *  每次都跳转到下一步，记录好每次已经走过的路程，然后继续走到下一步
     *  可以提前算好每个单词可以走到的下一步，用 map<string, vector<string>> 来代表每个单词可以走到的下一步
     *  如果路径中出现重复的，那么就跳过，不能继续走
     * @param  {string} beginWord        : 
     * @param  {string} endWord          : 
     * @param  {vector<string>} wordList : 
     * @return {vector<vector<string>>}  : 
     */
    // unordered_map<string, unordered_set<string>> nextSteps;
    // vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    //     // 检测 wordList 中是否存在 endWord
    //     bool exist = false;
    //     for (string word : wordList) {
    //         if (word == endWord) {
    //             exist = true;
    //             break;
    //         }
    //     }
    //     if (!exist)
    //         return {};
    //     wordList.push_back(beginWord);
    //     wordList.push_back(endWord);
    //     init_steps(wordList);
    //     vector<string> path;
    //     vector<vector<string>> ladders;
    //     set<string> pathWords;
    //     pathWords.insert(beginWord);
    //     path.emplace_back(beginWord);
    //     dfs(endWord, pathWords, path, wordList, ladders);
    //     return ladders;
    // }

    // void dfs(const string& endWord, set<string>& pathWords, vector<string>& path,
    //     vector<string>& wordList, vector<vector<string>>& ladders) {
    //     string word = path.back();
    //     if (path.back() == endWord) {
    //         if (ladders.size() == 0) {
    //             ladders.emplace_back(path);
    //         }            
    //         else if (path.size() == ladders[0].size()) {
    //             ladders.emplace_back(path);
    //         }            
    //         else if (path.size() < ladders[0].size()) {
    //             ladders.clear();
    //             ladders.emplace_back(path);
    //         }

    //     }        
    //     else {
    //         for (string nextWord : nextSteps[word]) {
    //             if (pathWords.find(nextWord) != pathWords.end())
    //                 continue;
    //             pathWords.insert(nextWord);
    //             path.emplace_back(nextWord);
    //             dfs(endWord, pathWords, path, wordList, ladders);
    //             pathWords.erase(nextWord);
    //             path.pop_back();
    //         }
    //     }
    // }
        
    // void init_steps(vector<string>& wordList) {
    //     for (string word : wordList) {
    //         for (string nextWord : wordList) {
    //             if (word == nextWord)
    //                 continue;
    //             if (nextSteps[word].find(nextWord) != nextSteps[word].end())
    //                 continue;   // 之前保存过二者的关系
    //             // 判断二者是否能够相互转换
    //             int n = word.size();
    //             int diff = 0;
    //             for (int i = 0; i < n; i++) {
    //                 if (word[i] == nextWord[i])
    //                     continue;
    //                 else 
    //                     diff++;
    //                 if (diff > 1)
    //                     break;
    //             }
    //             if (diff == 1) {
    //                 nextSteps[word].insert(nextWord);
    //                 nextSteps[nextWord].insert(word);
    //             }
    //         }
    //     }
    //     // for (auto item : nextSteps) {
    //     //     cout << item.first << ": ";
    //     //     for (auto str : item.second) {
    //     //         cout << str << ", ";
    //     //     }
    //     //     cout << endl;
    //     // }
    // }
};

int main(int argc, char const* argv []) {

    vector<string> wordList {"hot","dot","dog","lot","log","cog"};
    Solution so;
    auto ladders = so.findLadders("hit", "cog", wordList);
    for (auto path : ladders) {
        for (auto word : path) 
            cout << word << ", ";
        cout << endl;
    }
    
    return 0;
}