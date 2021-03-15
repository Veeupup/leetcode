#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    int* keys;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        keys = new int[1e6 + 10];
        memset(keys, 0, sizeof(int) * (1e6 + 10));
    }

    ~MyHashSet() {
        delete keys;
    }

    void add(int key) {
        keys[key] = 1;
    }

    void remove(int key) {
        keys[key] = 0;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return keys[key] == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main(int argc, char const* argv []) {




    return 0;
}