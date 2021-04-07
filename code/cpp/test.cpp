#include <bits/stdc++.h>
using namespace std;


namespace vv {
    void* memmove(void* dst, void* src, size_t n) {
        void* ret = dst;
        // 需要判断是否会重合
        if (dst <= src) {  // dst 在 src 的前面，那么应该从头开始复制，不然从尾部开始复制可能出现问题
            while (n--) {
                *(char*)dst = *(char*)src;
                dst = (char*)dst + 1;
                src = (char*)src + 1;
            }
        }
        else {  // dst 在 memove 的后面, 应该从后面往前拷贝
            dst = (char*)dst + n - 1;
            src = (char*)src + n - 1;
            while (n--) {
                *(char*)dst = *(char*)src;
                dst = (char*)dst - 1;
                src = (char*)src - 1;
            }
        }
        return ret;
    }
}

int main(int argc, char const* argv []) {

    char s1[10] = "hello";
    char s2[10];
    vv::memmove(s2, s1, 10);
    cout << (char*)s2 << endl;


    return 0;
}