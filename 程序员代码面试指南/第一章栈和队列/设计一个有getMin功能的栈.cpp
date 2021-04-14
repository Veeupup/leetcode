/**
 *  设计一个有 getMin 功能的栈
 *  
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class MinStack{
private:
    stack<int> sta;
    stack<int> minSta;
public:
    MinStack() {}
    void push(int x) {
        sta.push(x);
        if (minSta.empty() || x <= minSta.top())
            minSta.push(x);
    }
    
    void pop() {
        if (sta.empty())
            return;
        int x = sta.top();
        sta.pop();
        if (x == minSta.top())
            minSta.pop();
    }
    
    int getMin() {
        if (minSta.empty())
            return -1;
        return minSta.top();
    }
};

int main() {
    int n;
    cin >> n;
    string op;
    int x;
    MinStack sta;
    while (n--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            sta.push(x);
        }else if (op == "pop") {
            sta.pop();
        }else {
            cout << sta.getMin() << endl;
        }
    }
    
    return 0;
}
