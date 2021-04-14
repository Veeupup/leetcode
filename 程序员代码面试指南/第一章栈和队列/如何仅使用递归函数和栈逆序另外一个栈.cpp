#include <iostream>
#include <stack>
using namespace std;

int get_remove_last_element(stack<int>& sta) {
    int result = sta.top();
    sta.pop();
    if (sta.empty()) {
        return result;
    }else {
        int last = get_remove_last_element(sta);
        sta.push(result);
        return last;
    }
}

void reverse(stack<int>& sta) {
    if (sta.empty()) {
        return;
    }else {
        int x = get_remove_last_element(sta);
        reverse(sta);
        sta.push(x);
    }
}

int main() {
    int n;
    stack<int> sta;
    cin >> n;
    int num;
    while (n--) {
        cin >> num;
        sta.push(num);
    }
    // reverse(sta); // 有毒，输入从栈顶到栈底，又要逆序
    while (!sta.empty()) {
        cout << sta.top() << " ";
        sta.pop();
    }
    
    return 0;
}