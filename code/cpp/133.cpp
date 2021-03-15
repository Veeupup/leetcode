#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    /**
     * 首先遍历图，遍历的时候生成每一个新的节点 用 map 保存起来，
     * 然后第二次遍历，遍历的时候添加新的邻居
     * 这里就用 BFS 试试
     * @param  {Node*} node :
     * @return {Node*}      :
     */
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        unordered_map<Node*, Node*> visited;
        queue<Node*> qu;
        qu.push(node);
        visited[node] = new Node(node->val);
        while (!qu.empty()) {
            auto n = qu.front();
            qu.pop();
            for (auto& neighbor : n->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    qu.push(neighbor);
                }
                visited[n]->neighbors.emplace_back(visited[neighbor]);
            }
        }
        return visited[node];
    }

    unordered_map<Node*, Node*> visit;
    Node* cloneGraph2(Node* node) {
        if (node == nullptr)
            return node;

        if (visit.find(node) != visit.end())
            return visit[node];

        visit[node] = new Node(node->val);
        for (auto& neighbor : node->neighbors) {
            visit[node]->neighbors.emplace_back(cloneGraph2(neighbor));
        }
        return visit[node];
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {

    }
};

int main(int argc, char const* argv []) {




    return 0;
}