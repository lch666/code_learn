#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

// https://www.cnblogs.com/xiaohaigegede/p/14008121.html

std::mutex mtx; // 全局互斥锁
// 条件变量自身不包含条件，通常和if、while一起使用
// 并发两大需求（互斥、等待），互斥是因为线程间存在共享数据；等待是因为线程间存在依赖；等待的通知（轮训poll、事件event）
std::condition_variable produce, consume; // 全局条件变量
int shared_var = 0;  // 全局标志

void Consumer() {  // 消费者
  std::unique_lock<std::mutex> lck(mtx);
  // wait() 阻塞当前线程，直到条件变量被唤醒，收到notify();条件不成立时，线程wait,释放CPU
  // wait() 三步骤：释放互斥锁；等待条件变量的通知；再次获取互斥锁
  while (shared_var == 0) {  
    std::cout << "Consumer start --------" << std::endl;
    consume.wait(lck);  
    // consume.wait_for(lck, std::chrono::milliseconds(5000)); // notify通知唤醒，或者等待5000ms唤醒  
    // while (consume.wait_for(lck, std::chrono::milliseconds(5000)) == std::cv_status::timeout) {}
    std::cout << "Consumer end --------" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }
  std::cout << "Consumer shared_var is " << shared_var << std::endl;
  shared_var = 0;
  produce.notify_one();  // 通知一个等待的线程,通知之后produce条件变量所在的线程才会继续执行
}

void Producer(int id) {  // 生产者
  std::unique_lock<std::mutex> lck(mtx);
  while (shared_var != 0) produce.wait(lck);
  std::cout << "Producer shared_var is " << shared_var << std::endl;
  shared_var = id;
  consume.notify_one();
  // consume.notify_all();  // 通知所有等待线程
}

void Test1() {
  std::cout << "----------------------------start Test1----------------------------" << std::endl;
  std::thread consumers[10], producers[10];
  for (int i = 0; i < 10; i++) {
    consumers[i] = std::thread(Consumer);
    producers[i] = std::thread(Producer, i + 1);
  }

  for (int i = 0; i < 10; i++) {
    producers[i].join();
    consumers[i].join();
  }
  std::cout << "----------------------------end Test1----------------------------" << std::endl;
}

int main() {
  std::cout << "hello lch !" << std::endl;
  (void)Test1();
  std::cout << "end lch !" << std::endl;
  return 0;
}