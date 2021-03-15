#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. 0次，刚好相等
    // 2. 
    //      1次，插入，中间某个值缺少，缺少值的前后都是子串
    //      1次，删除，和插入一样，哪个长就交换
    //      1次，替换，从不同的那个字符切分，看前后是否相等
    bool oneEditAway(string first, string second) {
        if (first == second)
            return true;
        int len1 = first.size(), len2 = second.size();
        if (second.size() > first.size())
            swap(first, second);
        if (len1 - len2 > 1)    // 多于一次操作
            return false;
        int i = 0;
        for (; i < len2;++i) {
            if (first[i] != second[i])
                break;
        }
        if (len1 == len2) { // 只可能是替换
            return (first.substr(0, i) == second.substr(0, i)) && (first.substr(i+1) == second.substr(i+1));
        }// 只能是删除了
        if (i == len2) {    // 那么只可能是删除了最后一个
            return first.substr(0, len2) == second;
        }
        return (first.substr(0, i) == second.substr(0, i)) && (first.substr(i+1) == second.substr(i));
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}