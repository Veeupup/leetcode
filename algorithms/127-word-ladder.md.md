[127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/)

开始低估这个题目了，这个题是需要求出最短的路径，而不是随便一条路径，和 剑指offer 中的那题不一样。

如果需要求出最短路径，需要使用 BFS 来进行求解，而且可以使用双向 BFS 来减少搜索时间。

在之前到解题中，每次选择下一个节点的方法，是通过计算当前单词和 wordList 里每个单词的距离，从而得到下一步往哪里走，单词越多，单词长度越长，速度越慢。

在看了这个代码之后，发现原来可以不需要计算距离，我们直接写两层循环，

按个遍历当前单词的每个字母，然后对他进行替换 'a'-'z'，如果单词替换之后，能够在我们的节点中找到下一个词，那么就将哪个词加入队列中，同时把该节点移除候选节点。

```c++
//寻找下一个单词了
char ch;
for (int i = 0; i < tmp.length(); i++){
    ch = tmp[i];
    for (char c = 'a'; c <= 'z'; c++){
        //从'a'-'z'尝试一次
        if ( ch == c) continue;
        tmp[i] = c ;
        //如果找到的到
        if (  s.find(tmp) != s.end() ){
            q.push({tmp, step+1});
            s.erase(tmp) ; //删除该节点
        }
        tmp[i] = ch; //复原
    }

}
```

单向 BFS

```c++
class Solution{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        //加入所有节点，访问过一次，删除一个。
        unordered_set<string> s;
        for (auto &i : wordList) s.insert(i);

        queue<pair<string, int>> q;
        //加入beginword
        q.push({beginWord, 1});

        string tmp; //每个节点的字符
        int step;    //抵达该节点的step

        while ( !q.empty() ){
            if ( q.front().first == endWord){
                return (q.front().second);
            }
            tmp = q.front().first;
            step = q.front().second;
            q.pop();

            //寻找下一个单词了
            char ch;
            for (int i = 0; i < tmp.length(); i++){
                ch = tmp[i];
                for (char c = 'a'; c <= 'z'; c++){
                    //从'a'-'z'尝试一次
                    if ( ch == c) continue;
                    tmp[i] = c ;
                    //如果找到的到
                    if (  s.find(tmp) != s.end() ){
                        q.push({tmp, step+1});
                        s.erase(tmp) ; //删除该节点
                    }
                tmp[i] = ch; //复原
                }
               
            }
        }
        return 0;
    }
};
```

双向 BFS

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end() ) return 0;
        // 初始化起始和终点
        unordered_set<string> beginSet, endSet, tmp, visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int len = 1;

        while (!beginSet.empty() && !endSet.empty()){
            if (beginSet.size() > endSet.size()){
                tmp = beginSet;
                beginSet = endSet;
                endSet = tmp;
            }
            tmp.clear();
            for ( string word : beginSet){
                for (int i = 0; i < word.size(); i++){
                    char old = word[i];
                    for ( char c = 'a'; c <= 'z'; c++){
                        if ( old == c) continue;
                        word[i] = c;
                        if (endSet.find(word) != endSet.end()){
                            return len+1;
                        }
                        if (visited.find(word) == visited.end() && dict.find(word) != dict.end()){
                            tmp.insert(word);
                            visited.insert(word);
                        }
                    }
                    word[i] = old;
                }
            }
            beginSet = tmp;
            len++;
            

        }
        return 0;
    }
};
```

https://leetcode-cn.com/problems/word-ladder/solution/cpp-yi-ge-si-lu-de-zhuan-bian-cong-1156msjia-su-da/

