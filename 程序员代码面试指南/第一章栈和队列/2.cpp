#include <iostream>
#include <stack>
#include <string>
using namespace std;

/**
 *  使用两个栈实现队列
 */

template<typename T>
class QueueSta {
private:
    stack<T> sta1;
    stack<T> sta2;
public:
    void add(T x) {
        sta1.push(x);
    }
    
    void poll() {
        if (sta1.empty() && sta2.empty())
            return;
        if (!sta2.empty())
            sta2.pop();
        else {
            while (!sta1.empty()) {
                sta2.push(sta1.top());
                sta1.pop();
            }
            this->poll();
        }
    }
    
    T peek() {
        if (sta1.empty() && sta2.empty())
            return T{0};
        if (!sta2.empty())
            return sta2.top();
        else {
            while (!sta1.empty()) {
                sta2.push(sta1.top());
                sta1.pop();
            }
            return this->peek();
        }
    }
};

int main() {
    int n;
    cin >> n;
    string op;
    int x;
    QueueSta<int> q;
    while (n--) {
        cin >> op;
        if (op == "add") {
            cin >> x;
            q.add(x);
        }else if (op == "poll") {
            q.poll();
        }else {
            cout << q.peek() << endl;
        }
    }
    
    return 0;
}
