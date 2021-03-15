#include <bits/stdc++.h>
using namespace std;

namespace vv {
    template <class T>
    /**
     * 需要注意的点：
     *  1. 指针指向引用计数
     *  2. 重载 copy 构造函数
     *  3. 重载 assignment 构造函数
     *  4. 重载析构函数 适当的时候释放内存
     *  5. 重载 *
     *  6. 重载 ->
     *  7.
     * @param  {} undefined :
     */
    class shared_ptr {
    private:
        T* ptr;
        int* cnt;
    public:
        shared_ptr(T* p) : cnt(new int(1)), ptr(p) {}
        T* operator->() {
            return ptr;
        }
        T& operator*() {
            return *ptr;
        }
        int use_count() {
            return *cnt;
        }
        // 拷贝构造函数，增加引用计数
        shared_ptr(const shared_ptr<T>& other) : cnt(&(++(*other.cnt))), ptr(other.ptr) {}
        shared_ptr& operator=(const shared_ptr<T>& other) {
            ++(*other.cnt); // 增加引用计数
            // 如果原来有指向的对象，那么判断是否需要析构
            if (this->ptr && --this->cnt == 0) {
                delete cnt;
                delete ptr;
            }
            this->cnt = other.cnt;
            this->ptr = other.ptr;
            return *this;
        }
        ~shared_ptr() {
            if (--(*this->cnt) == 0) {
                cout << "delete ptr" << endl;
                delete cnt;
                delete ptr;
            }
        }
        bool unique() {
            return *cnt == 1;
        }
    };

    template <class T>
    class Shared_ptr {
    private:
        int* _pRefCount;
        T* _pPtr;
        mutex* _pMutex;
    public:
        Shared_ptr(T* ptr = nullptr) : _pPtr(ptr), _pRefCount(new int(1)), _pMutex(new mutex) {}
        ~Shared_ptr() {
            Release();
        }
        Shared_ptr(const Shared_ptr<T>& sp) : _pPtr(sp._pPtr), _pRefCount(sp._pRefCount), _pMutex(sp._pMutex) {
            AddRefCount();
        }
        Shared_ptr& operator=(const Shared_ptr<T>& sp) {
            if (_pPtr != sp._pPtr) {    // 不同类型才能赋值
                Release();
                _pPtr = sp._pPtr;
                _pRefCount = sp._pRefCount;
                _pMutex = sp._pMutex;
                AddRefCount();
            }
            return *this;
        }
        T& operator*() {
            return *_pPtr;
        }
        T* operator->() {
            return _pPtr;
        }
        int use_count() {
            return *_pRefCount;
        }
        T* get() {
            return _pPtr;
        }
    private:
        void Release() {
            bool deleteFlag = false;
            _pMutex->lock();
            if (--(*_pRefCount) == 0) {
                delete _pRefCount;
                delete _pPtr;
                deleteFlag = true;
            }
            _pMutex->unlock();
            if (deleteFlag)
                delete _pMutex;
        }
        void AddRefCount() {
            _pMutex->lock();
            ++(*_pRefCount);
            _pMutex->unlock();
        }
    };
}


int main(int argc, char const* argv []) {

    vv::Shared_ptr<string> p(new string(10, '9'));
    cout << *p << endl;
    cout << p->size() << endl;
    cout << p.use_count() << endl;
    auto q(p);
    cout << p.use_count() << endl;
    auto q2 = p;
    cout << p.use_count() << endl;

    return 0;
}
