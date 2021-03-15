#include <bits/stdc++.h>
using namespace std;

int T, n, k;
multiset<int> S;

int Mex(set<int>& s2) {
    vector<int> vec(s2.begin(), s2.end());
    sort(vec.begin(), vec.end());
    if (vec.size() == 0 || vec[0] > 0)
        return 0;
    int size = vec.size();
    for (int i = 0; i < size; i++) {
        if (vec[i] != i)
            return i;
    }
    return size;
}

int main(int argc, char const* argv []) {

    cin >> T;
    while (T--) {
        set<int> s2;
        cin >> n >> k;
        int num;
        int max_num = INT_MIN;
        while (n--) {
            cin >> num;
            S.insert(num);
            s2.insert(num);
            max_num = max(max_num, num);
        }
        while (k--) {
            int a = Mex(s2);
            int b = max_num;
            int tmp = (a + b + 1) / 2;
            S.insert(tmp);
            s2.insert(tmp);
            max_num = max(max_num, tmp);
        }
        S.clear();
        cout << s2.size() << endl;
    }


    return 0;
}
