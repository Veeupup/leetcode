#include <iostream>
#include <stack>
using namespace std;

/**
 * 一个栈中元素的类型为整型，现在想将该栈从顶到底按从大到小的顺序排序，只许申请一个栈。
 * 除此之外，可以申请新的变量，但不能申请额外的数据结构。如何完成排序？
 *
 */

int main() {
    stack<int> s1, s2;
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        s1.push(x);
    }
    while (!s1.empty()) {
        int num = s1.top();
        s1.pop();
        if (s2.empty()) {
            s2.push(num);
        }else {
            while (!s2.empty() && num < s2.top()) {
                s1.push(s2.top());
                s2.pop();
            }
            s2.push(num);
        }
    }
    while (!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    
    return 0;
}
