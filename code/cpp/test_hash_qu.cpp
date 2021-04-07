#include <bits/stdc++.h>
using namespace std;

class HashQ {
private:
    unordered_set<int> hashtable;
    queue<unordered_set<int>::iterator> qu;
public:
    void Insert(int key) {
        hashtable.insert(key);
        qu.push(hashtable.find(key));
    }

    bool Find(int key) {
        auto it = hashtable.find(key);
        if (it != hashtable.end())
            return true;
        return false;
    }

    void Pop() {
        auto it = qu.front();
        hashtable.erase(it);
    }

};

int main(int argc, char const* argv []) {

    


    return 0;
}