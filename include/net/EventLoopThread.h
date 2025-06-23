#ifndef MYMUDUO_NET_EVENTLOOPTHREAD_H
#define MYMUDUO_NET_EVENTLOOPTHREAD_H

#include "base/noncopyable.h"
#include "base/Thread.h"

#include <functional>
#include <mutex>
#include <condition_variable>
#include <string>

/*
在客户端中一般要使用 EventLoopThread 类，其主要目的是为了 避免阻塞主线程 并实现高效的异步网络事件处理。
可以确保客户端的事件循环能够在独立线程中运行，防止主线程因等待网络事件（如连接、数据传输）而阻塞。
*/

namespace mymuduo {
namespace net {

class EventLoop;

/**
 * @brief 事件循环线程类
 * 
 * 该类用于创建一个新线程，并在该线程中运行事件循环。
 * 主要用于IO线程池中，每个IO线程都包含一个EventLoop。
 */
class EventLoopThread : noncopyable {
public:
    // 线程初始化回调函数类型
    using ThreadInitCallback = std::function<void(EventLoop*)>;

    /**
     * @brief 构造函数
     * @param cb 线程初始化回调函数
     * @param name 线程名称
     */
    EventLoopThread(const ThreadInitCallback& cb = ThreadInitCallback(),
                   const std::string& name = std::string());
    
    /**
     * @brief 析构函数
     * 如果线程还在运行，会等待线程退出
     */
    ~EventLoopThread();

    /**
     * @brief 启动线程并返回其EventLoop对象
     * 
     * 该函数会创建新线程并等待EventLoop创建完成。
     * 线程函数会创建EventLoop对象并通知此函数。
     * 
     * @return EventLoop* 新创建的EventLoop对象指针
     */
    EventLoop* startLoop();

private:
    /**
     * @brief 线程函数
     * 
     * 创建EventLoop对象并运行事件循环
     */
    void threadFunc();

    EventLoop* loop_;        // loop_指针指向一个EventLoop对象（和subLoop是一个概念）
    bool exiting_;          // 是否退出
    Thread thread_;         // 线程对象
    std::mutex mutex_;      // 互斥锁
    std::condition_variable cond_;  // 条件变量
    ThreadInitCallback callback_;   // 回调函数
};

} // namespace net
} // namespace mymuduo

#endif // MYMUDUO_NET_EVENTLOOPTHREAD_H 