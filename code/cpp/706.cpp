#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
    int(*maps)[2];  // 二维数组指针
    const int MAXN = 1e6 + 10;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        maps = new int[MAXN][2];
        memset(maps, 0, sizeof(int) * MAXN * 2);
    }
    ~MyHashMap() {
        delete []maps;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        maps[key][0] = 1;
        maps[key][1] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (maps[key][0] == 0)
            return -1;
        return maps[key][1];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        maps[key][0] = 0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(int argc, char const* argv []) {




    return 0;
}