#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> sta;
    stack<int> minSta;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        sta.push(x);
        if (minSta.empty() || x <= minSta.top())
            minSta.push(x);
    }

    void pop() {
        int top = sta.top();
        sta.pop();
        if (top == minSta.top())
            minSta.pop();
    }

    int top() {
        return sta.top();
    }

    int getMin() {
        return minSta.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char const* argv []) {




    return 0;
}