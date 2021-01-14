#include <bits/stdc++.h>
using namespace std;

/**
* 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
*  辅助栈，维持一个非严格降序的栈
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        sta_A.push(x);
        if (sta_B.empty() || x <= sta_B.top())
            sta_B.push(x);
    }
    
    void pop() {
        if (sta_A.top() == sta_B.top())
            sta_B.pop();
        sta_A.pop();
    }
    
    int top() {
        return sta_A.top();
    }
    
    int min() {
        return sta_B.top();
    }
private:
    stack<int> sta_A;
    stack<int> sta_B;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main()
{ 
    MinStack m;
    m.push(2);
    m.push(-1);
    m.push(-5);
    m.push(10);
    cout << m.min() << endl;
    m.pop();


    return 0;
}