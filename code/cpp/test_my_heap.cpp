#include <bits/stdc++.h>
using namespace std;


struct Node {
    int x, y;
    Node(int a = 0, int b = 0) : x(a), y(b) {};
    friend bool operator<(const Node& a, const Node& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y > b.y;
    }
    friend istream& operator>>(istream& in, Node& node) {
        in >> node.x >> node.y;
        return in;
    }
    friend ostream& operator<<(ostream& out, Node& node) {
        out << node.x << ", " << node.y;
        return out;
    }
};

struct cmp2 {
    bool operator()(int a, int b) {
        return a < b;
    };
};

int main(int argc, char const* argv []) {

    priority_queue<int> pq; // 默认是大顶堆
    for (int i = 0; i < 10; ++i) {
        pq.push(rand() % 100);
    }
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    cout << "  =========  " << endl;

    priority_queue<int, vector<int>, greater<int>> my_pq;
    for (int i = 0; i < 10; ++i) {
        my_pq.push(rand() % 100);
    }
    while (!my_pq.empty()) {
        cout << my_pq.top() << endl;
        my_pq.pop();
    }
    cout << "  =========  " << endl;

    priority_queue<Node> node_pq;
    for (int i = 0; i < 10; ++i) {
        node_pq.push(Node(rand() % 100, rand() % 100));
    }
    while (!node_pq.empty()) {
        Node a = node_pq.top();
        cout << a << endl;
        node_pq.pop();
    }
    cout << "  =========  " << endl;

    priority_queue<int, vector<int>, cmp2> my_struct_pq;
    for (int i = 0; i < 10; ++i) {
        my_struct_pq.push(rand() % 100);
    }
    while (!my_struct_pq.empty()) {
        cout << my_struct_pq.top() << endl;
        my_struct_pq.pop();
    }
    cout << "  =========  " << endl;

    return 0;
}