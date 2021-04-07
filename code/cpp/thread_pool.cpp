#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

class ThreadPool {
    using Task = function<void()>;
    // 线程池
    vector<thread> pool;
    // 任务队列
    queue<Task> tasks;
    // 同步
    mutex latch;
    // 条件阻塞
    condition_variable has_task;
    // 是否提交关闭
    atomic<bool> stopped;
    // 空闲线程数量
    atomic<int> idlThrNum;
public:
    ThreadPool(unsigned short size = 4) : stopped(false) {
        idlThrNum = size < 1 ? 1 : size;
        for (size_t i = 0; i < size; i++) {
            pool.emplace_back(
                [this]() {  // 工作函数
                    while (!stopped) {
                        function<void()> task;
                        {
                            unique_lock<mutex> lock(latch);
                            has_task.wait(lock,
                                [this] {
                                    return stopped.load() || !tasks.empty();    // 当非空或者停止的时候唤醒当前线程
                                });
                            if (stopped && tasks.empty())
                                return;
                            task = move(tasks.front());
                        }
                        idlThrNum--;
                        task();
                        idlThrNum++;
                    }
                }
            );
        }
    }
    ~ThreadPool() {
        stopped.store(true);
        has_task.notify_all();
        for (thread& th : pool) {
            if (th.joinable())  // 等待所有线程执行完毕
                th.join();
        }     
    }
    // 自动推断每个函数的返回值
    template<class F, class... Args>
    auto commit(F&& f, Args&&... args) -> future<decltype(f(args...))> {
        if (stopped)
            throw runtime_error("commit on pool is stopped");
        using RetType = decltype(f(args...));   // 返回值
        auto task = make_shared<packaged_task<RetType()>> (
            bind(forward<F>(f), forward<Args>(args))
        );  // ??? 这是啥啊
        future<RetType> future = task->get_future();
        {
            unique_lock<mutex> lock(latch);
            tasks.emplace([task]() {
                (*tash)();
            });
        }
        has_task.notify_one();    
        return future;
    }
};

int main(int argc, char const* argv []) {




    return 0;
}