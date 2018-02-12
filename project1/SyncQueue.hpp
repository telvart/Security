
#ifndef SYNCQUEUE
#define SYNCQUEUE


#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class SyncQueue
{
  public:
    SyncQueue()
    {
    //  queue = std::queue<T>();
    }

    void enqueue(T item)
    {
      std::unique_lock<std::mutex> theLock(pushPopMutex);
      queue.push(item);
      theLock.unlock();
      signal.notify_one();
    }

    T dequeue()
    {
      std::unique_lock<std::mutex> theLock(pushPopMutex);
      while(queue.empty())
      {
        signal.wait(theLock);
      }
      T ret = queue.front();
      queue.pop();
      return ret;
    }

    bool empty()
    {
      return queue.empty();
    }

  std::queue<T> queue;
  std::mutex pushPopMutex;
  std::condition_variable signal;
};

#endif
