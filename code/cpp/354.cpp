#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 俄罗斯套娃信封问题
     *  1.  思路
     *      给每个信封一个 id（int）
     *      遍历所有信封，每张信封记录下自己能够被哪些其他信封装起来；
     *      然后 找到每张信封所存在的回溯树，记录下最深的深度
     *      vector<int, vector<int>> fathers; fathers 中只用存储对应的父亲信封的 id 即可
     *      然后对每个信封进行 backtrace 回溯，找到最深的树
     *
     *      优化：
     *      1. 遍历所有信封之前，可以先根据信封的 宽度 排序，这样找比自己大的信封的时候就只需要从当前下标之后的信封开始查找
     *      2. 回溯进行剪枝，因为回溯树可能出现重复的路径，记录下每个信封可能所在的最大深度，如果此次遍历当前的深度小于这个信封能够
     *          到达的最大深度，那么直接剪枝
     * @param  {vector<vector<int>>} envelopes : 信封的长宽的集合
     * @return {int}                           : 最大的套娃的深度
     */
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0 || n == 1)
            return n;
        // 对信封根据宽度高度进行排序
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& env1, vector<int>& env2) {
            if (env1[0] == env2[0])
                return env1[1] < env2[1];
            return env1[0] < env2[0];
        });
        
        vector<vector<int>> fathers(n);   // 记录下每个信封可以被哪些信封装起来
        for (int i = 0; i < n; i++) {
            int now_w = envelopes[i][0], now_h = envelopes[i][1];
            for (int j = i + 1; j < n; j++) {
                if (envelopes[j][0] > now_w && envelopes[j][1] > now_h) {
                    fathers[i].push_back(j);
                }
            }
        }
        int maxDepth = 1;
        vector<int> env_max_depth(n); // 记录下每个信封可以到达的最大深度,默认初始化初始为 0
        for (int i = 0; i < n; i++) {
            if (env_max_depth[i] > 1)   // 如果曾经当过别人的父亲信封，那么不用搜索了
                continue;
            backtrace(i, envelopes, fathers, 1, env_max_depth, maxDepth);
        }
        return maxDepth;
    }
        
    /**
     * 
     * @param  {int} id                        : 当前的 id
     * @param  {vector<vector<int>>} envelopes : 信封的大小
     * @param  {vector<vector<int>>} fathers   : 每个信封的父亲信封
     * @param  {int} depth                     : 当前深度
     * @param  {vector<int>} env_max_depth     : 每个信封到达过的最大深度
     * @param  {int} maxDepth                  : 最大深度
     */
    void backtrace(int id, vector<vector<int>>& envelopes, vector<vector<int>>& fathers,  int depth, vector<int>& env_max_depth, int& maxDepth) {
        if (fathers[id].size() == 0) {  // 当前信封不能再套上新的信封
            env_max_depth[id] = depth;
            maxDepth = max(depth, maxDepth);
        }else {
            if (depth < env_max_depth[id])  // 如果当前深度小于曾经到达过的最大深度，那么直接返回
                return;
            env_max_depth[id] = max(depth, env_max_depth[id]);  // 更新当前 id 能够到达的最大深度
            for (int father_id : fathers[id]) {
                if (env_max_depth[father_id] <= depth + 1) {
                    backtrace(father_id, envelopes, fathers, depth + 1, env_max_depth, maxDepth);
                }
            }
        }
    }
};

class Solution2 {
public:
    /**
     * 优化：
     *  从最大的信封开始计算，从尾部向头部遍历，每次记录下尾部能够到达的最大深度
     * @param  {vector<vector<int>>} envelopes : 
     * @return {int}                           : 
     */
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0 || n == 1)
            return n;
        // 对信封根据宽度高度进行排序
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& env1, vector<int>& env2) {
            if (env1[0] == env2[0])
                return env1[1] < env2[1];
            return env1[0] < env2[0];
        });
        
        vector<vector<int>> fathers(n);   // 记录下每个信封可以被哪些信封装起来
        for (int i = 0; i < n; i++) {
            int now_w = envelopes[i][0], now_h = envelopes[i][1];
            for (int j = i + 1; j < n; j++) {
                if (envelopes[j][0] > now_w && envelopes[j][1] > now_h) {
                    fathers[i].push_back(j);
                }
            }
        }
        int maxDepth = 1;
        vector<int> env_max_depth(n, 1); // 记录下每个信封可以到达的最大深度,默认初始化初始为 0
        for (int i = n - 1; i >= 0; i--) {
            int maxFatherDepth = 0;
            for (int father_id : fathers[i]) {
                maxFatherDepth = max(env_max_depth[father_id], maxFatherDepth);
            }
            env_max_depth[i] = env_max_depth[i] + maxFatherDepth;
            maxDepth = max(maxDepth, env_max_depth[i]);
        }
        return maxDepth;
    }
        
};

int main(int argc, char const* argv []) {

    Solution2 so;
    vector<vector<int>> envlopes{{{5,4},{6,4},{6,7},{2,3}}};
    cout << so.maxEnvelopes(envlopes) << endl;


    return 0;
}