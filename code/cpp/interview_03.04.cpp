#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> sta1, sta2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        sta1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (sta2.empty()) {
            while (!sta1.empty()) {
                sta2.push(sta1.top());
                sta1.pop();
            }
        }
        if (sta2.empty())
            return -1;
        int ret = sta2.top();
        sta2.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        if (sta2.empty()) {
            while (!sta1.empty()) {
                sta2.push(sta1.top());
                sta1.pop();
            }
        }
        if (sta2.empty())
            return -1;
        int ret = sta2.top();
        return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return sta1.empty() && sta2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, char const* argv []) {




    return 0;
}