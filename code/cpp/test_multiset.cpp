#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const* argv []) {

    multimap<int, int> maps;
    maps.insert({ 1, 1 });
    maps.insert({ 1, 2 });
    maps.insert({ 1, 3 });


    auto range = maps.equal_range(2);
    assert(range.first == maps.end());
    for (auto i = range.first; i != range.second; ++i) {
        cout << i->first << ": " << i->second << endl;
    }

    maps.erase(1);
    assert(maps.empty());

    return 0;
}