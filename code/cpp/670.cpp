#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        if (num <= 9) 
            return num;
        string s = to_string(num);
        string temp(s);

        // lambda 将数组排序
        sort(temp.begin(), temp.end(), [](char a, char b) {return a > b;});

        int pos = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != temp[i]) {
                pos = i;
                break;
            }
        }
        if (pos == -1)
            return num;
        // 从后往前找到要交换的位置
        for (int i = s.size() - 1; i >= pos + 1; i--)
        {
            if(s[i] == temp[pos]) {
                swap(s[i], s[pos]);
                break;
            }
        }
    
        return stoi(s);
    }
};

int main() {
    int a[10]{0};
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << endl;
    }
    

    return 0;
}
