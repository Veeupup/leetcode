#include <bits/stdc++.h>
using namespace std;

class SortedStack {
private:
    stack<int> sta1, sta2;
public:
    SortedStack() {

    }

    void push(int val) {
        if (sta1.empty()) {
            sta1.push(val);
            return;
        }
        while (!sta1.empty() && val > sta1.top()) {
            sta2.push(sta1.top());
            sta1.pop();
        }
        sta1.push(val);
        while (!sta2.empty()) {
            sta1.push(sta2.top());
            sta2.pop();
        }
    }

    void pop() {
        if (!sta1.empty())
            sta1.pop();
    }

    int peek() {
        if (sta1.empty())
            return -1;
        return sta1.top();
    }

    bool isEmpty() {
        return sta1.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */

int main(int argc, char const* argv []) {




    return 0;
}