#include <iostream>
#include <future>
#include <thread>
#include <mutex>

void CallBack() {
  std::cout << "now execute callback fuction" << std::endl;
}

int ThreadTest1() {
  int temp = 0;
  // while (true) {
  //   std::cout << temp++ << std::endl;
  // }
  for (int i = 0; i < 20; ++i) {
    if (i == 5) CallBack();
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return  0;
}

void ThreadTest2() {
  std::cout << "now execute ThreadTest2" << std::endl;
}

auto ThreadTest3 = [] {
  std::cout << "now execute ThreadTe3 lambda" << std::endl;
};

void Test1() {
  std::cout << "----------------------------start Test1----------------------------" << std::endl;
  std::future<int> thread_id1 = std::async(std::launch::async, ThreadTest1);
  std::cout << "first print" << std::endl;
  int ret1 = thread_id1.get();   // 等待线程结束，并返回结果
  std::cout << "thread id 1 result is " << ret1 << std::endl;

  std::future<void> thread_id2 = std::async(ThreadTest2);
  
  
  std::thread thread_id3(ThreadTest1);
  thread_id3.join();  // 阻塞作用，等待执行完
  std::cout << std::endl << "thread_id3 joinable value is " << thread_id3.joinable() << std::endl;

  std::thread thread_id4(ThreadTest3);
  thread_id4.detach();  // 守护线程，异步执行，无需等待线程执行完
  std::cout << std::endl << "thread_id4 joinable value is " << thread_id4.joinable() << std::endl;
  std::cout << "----------------------------end Test1----------------------------" << std::endl;
}

std::mutex mtx_;
std::mutex test2_mtx_;
static int number_ = 0;
void Print1(std::string td) {
  std::lock_guard<std::mutex> t_mtx(mtx_);  // 作用域范围内有效
  // mtx_.lock();
  for (int i = 0; i < 10; i++) {
    std::cout << ++number_ << " ";
  }
  std::cout << std::endl;
  // mtx_.unlock();
  std::cout << "end execute Print1 " << td << std::endl;
} 

void Test2() {
  std::cout << "----------------------------start Test2----------------------------" << std::endl;
  std::unique_lock<std::mutex> t_mtx(test2_mtx_);  // 作用域范围内有效，相比lock_guard可以灵活使用lock和unlock
  std::thread td1(Print1, "td1");
  std::thread td2(Print1, "td2");
  std::thread td3(Print1, "td3");
  std::thread td4(Print1, "td4");
  td1.join();
  td2.join();
  td3.detach();
  td4.detach();
  std::cout << "----------------------------end Test2----------------------------" << std::endl;
}

int main() {
  std::cout << "hello lch!" << std::endl;
  (void)Test1();
  (void)Test2();
  std::cout << "end lch!" << std::endl;
  return 0;
}