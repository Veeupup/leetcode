#include <bits/stdc++.h>
using namespace std;

namespace vv {
    /**
     * 需要做的事情：
     *  构造函数 申请空间
        析构函数 释放空间
        拷贝构造函数，禁用，不支持
        拷贝赋值函数，禁用，不支持
        reset()：释放源资源，指向新资源
        release()：返回资源，放弃对资源的管理
        get()：返回资源，只是供外部使用，依然管理资源
        operator bool (): 是否持有资源
        operator * ()
        operator -> ()

     * @param  {} undefined :
     */
    template <class T>
    class Unique_ptr {
    private:
        T* _pPtr;
    public:
        Unique_ptr(const Unique_ptr&) = delete; // 禁用拷贝
        Unique_ptr& operator=(const Unique_ptr&) = delete;  // 禁用赋值拷贝
        Unique_ptr(T* ptr = nullptr) : _pPtr(ptr) {}
        ~Unique_ptr() { del(); }
        T* operator->() {
            return _pPtr;
        }
        T& operator*() {
            return *_pPtr;
        }
        T* get() {
            return _pPtr;
        }
        T* release() {
            T* pTmp = _pPtr;
            _pPtr = nullptr;
            return _pPtr;   // 由调用方管理资源
        }
        void reset(T* p1) {
            del();
            _pPtr = p1;
        }
    private:
        void del() {
            if (nullptr == _pPtr)
                return;
            delete _pPtr;
            _pPtr = nullptr;
        }
    };
}

int main(int argc, char const* argv []) {

    vv::Unique_ptr<string> p(new string(10, 'a'));
    cout << p->size() << endl;
    // auto q(p);
    // auto q2 = p;


    return 0;
}