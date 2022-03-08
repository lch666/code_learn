#include <iostream>
#include <mutex>

class SafeSingleton {
private:
  SafeSingleton() = default;
  ~SafeSingleton() = default;
  static SafeSingleton* instance;
  static std::mutex s_mtx;
public:
  static SafeSingleton* GetInstance() {
    if (nullptr == instance) {
      // 对s_mtx上锁，保证下面作用域的代码只能被一个线程访问
      // std::unique_lock<std::mutex> mtx(s_mtx);
      std::lock_guard<std::mutex> mtx(s_mtx); 
      if (nullptr == instance) {
        instance = new SafeSingleton();
      }
    }
    return instance;
  } 
};

SafeSingleton* SafeSingleton::instance;
std::mutex SafeSingleton::s_mtx;

int main() {
  std::cout << "hello lch!" << std::endl;
  std::cout << SafeSingleton::GetInstance() << std::endl;
  std::cout << SafeSingleton::GetInstance() << std::endl;
  std::cout << SafeSingleton::GetInstance() << std::endl;
  SafeSingleton *c1 = SafeSingleton::GetInstance();
  std::cout << "end lch!" << std::endl;
  return 0;
}