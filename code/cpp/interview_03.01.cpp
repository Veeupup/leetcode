#include <bits/stdc++.h>
using namespace std;

class TripleInOne {
private:
    int* sta;
    int* sizes;
    int stack_size;
public:
    TripleInOne(int stackSize) : stack_size(stackSize) {
        sta = new int[stackSize * 3];
        sizes = new int[3];
        memset(sizes, 0, sizeof(int) * 3);
    }

    void push(int stackNum, int value) {
        if (sizes[stackNum] == stack_size)
            return;
        sta[stackNum * stack_size + sizes[stackNum]] = value;
        ++sizes[stackNum];
    }

    int pop(int stackNum) {
        if (sizes[stackNum] == 0)
            return -1;
        return sta[stackNum * stack_size + --sizes[stackNum]];
    }

    int peek(int stackNum) {
        if (sizes[stackNum] == 0)
            return -1;
        return sta[stackNum * stack_size + sizes[stackNum] - 1];
    }

    bool isEmpty(int stackNum) {
        return sizes[stackNum] == 0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */

 /**
  * Your TripleInOne object will be instantiated and called as such:
  * TripleInOne* obj = new TripleInOne(stackSize);
  * obj->push(stackNum,value);
  * int param_2 = obj->pop(stackNum);
  * int param_3 = obj->peek(stackNum);
  * bool param_4 = obj->isEmpty(stackNum);
  */

int main(int argc, char const* argv []) {




    return 0;
}