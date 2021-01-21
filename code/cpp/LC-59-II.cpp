#include <bits/stdc++.h>
using namespace std;

/**
 * 最大队列，可以模仿单调栈来实现
 * @param  {c []} undefined : 
 */
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (q2.empty())
            return -1;
        return q2.front();
    }
    
    void push_back(int value) {
        q1.push(value);
        while (!q2.empty() && q2.back() < value)
            q2.pop_back();
        q2.push_back(value);
    }
    
    int pop_front() {
        if (q1.empty())
            return -1;
        int val = q1.front();
        q1.pop();
        if (val == q2.front())
            q2.pop_front();
        return val;
    }
private:
    queue<int> q1;  // 保存真实的队列
    deque<int> q2;  // 非严格单调减少
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}