#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    *   取石子
        每次都从最多和最少的石子堆中取得石子，直到最少的一个为空，再根据二者中较少的那个来计算
        [6,5,4] => [5,6,4] => [4,6,5] => [4,5,6]
    */
    int maximumScore(int a, int b, int c) {
        auto exchange = [&]() {
            if (a > b) 
                swap(a, b);
            if (a > c)
                swap(a, c);
            if (b > c)
                swap(b, c);
        };
        exchange();
        int ans = 0;
        while (a != 0 && b != 0 && c != 0) {
            a--;
            c--;
            ans++;
            exchange();
        }   // 直到有一个为 0
        ans += min(b, c);
        return ans;
    }
};

int main(int argc, char const *argv[])
{ 

    

    
    return 0;
}