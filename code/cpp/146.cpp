#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> maps;
    const int cap_;
public:
    LRUCache(int capacity) : cap_(capacity) {

    }

    int get(int key) {
        auto it = maps.find(key);
        if (it == maps.end())
            return -1;
        auto pos = it->second;  // pos 是 cache 中的迭代器
        int val = pos->second;
        cache.erase(pos);
        cache.push_front({ key, val });
        maps[key] = cache.begin();
        return val;
    }

    void put(int key, int value) {
        auto newNode = std::make_pair(key, value);

        auto it = maps.find(key);
        if (it != maps.end()) { // 此时是更新，把之前的删除
            cache.erase(it->second);
        }
        else {
            if (cache.size() == cap_) {
                int last_key = cache.back().first;
                cache.pop_back();
                maps.erase(last_key);
            }
        }
        cache.push_front(newNode);
        maps[key] = cache.begin();
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const* argv []) {




    return 0;
}