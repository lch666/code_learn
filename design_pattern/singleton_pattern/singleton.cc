#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

template<typename T>
class Singleton {
 public:
  static T& GetInstance() {
    static T instance;
    return instance;
  }

  Singleton(T&&) = delete;
  Singleton(const T&) = delete;
  void operator= (const T&) = delete;

 protected:
  Singleton() = default;
  virtual ~Singleton() = default;
};

template<typename T, bool is_thread_safe = true>
class LazySingleton {
 private:
  static std::unique_ptr<T> t_;
  static std::mutex mtx_;

 public:
  static T& GetInstance() {
    if (is_thread_safe == false) {
      if (t_ == nullptr)
        t_ = std::unique_ptr<T>(new T);
      return *t_;
    }

    if (t_ == nullptr) {
      std::unique_lock<std::mutex> unique_locker(mtx_);
      if (t_ == nullptr)
        t_ = std::unique_ptr<T>(new T);
      return *t_;
    }
  }

  LazySingleton(T&&) = delete;
  LazySingleton(const T&) = delete;
  void operator= (const T&) = delete;

 protected:
  LazySingleton() = default;
  virtual ~LazySingleton() = default;
};

template<typename T, bool is_thread_safe>
std::unique_ptr<T> LazySingleton<T, is_thread_safe>::t_;

template<typename T, bool is_thread_safe>
std::mutex LazySingleton<T, is_thread_safe>::mtx_;

template<typename T>
class EagerSingleton {
 private:
  static T* t_;

 public:
  static T& GetInstance() {
    return *t_;
  }

  EagerSingleton(T&&) = delete;
  EagerSingleton(const T&) = delete;
  void operator= (const T&) = delete;

 protected:
  EagerSingleton() = default;
  virtual ~EagerSingleton() = default;
};

template<typename T>
T* EagerSingleton<T>::t_ = new (std::nothrow) T;

class Foo : public Singleton<Foo> {
 public:
  void operator() () {
    std::cout << &GetInstance() << std::endl;
  }
};

class LazyFoo : public LazySingleton<LazyFoo, false> {
 public:
  void operator() () {
    std::cout << &GetInstance() << std::endl;
  }
};

class ThreadSafeLazyFoo : public LazySingleton<ThreadSafeLazyFoo> {
 public:
  void operator() () {
    std::cout << &GetInstance() << std::endl;
  }
};

class EagerFoo : public EagerSingleton<EagerFoo> {
 public:
  void operator() () {
    std::cout << &GetInstance() << std::endl;
  }
};

void SingletonTest() {
  
  std::thread t1, t2;

  // t1 = std::thread((Foo()));
  // t2 = std::thread((Foo()));
  // t1.join();
  // t2.join();
  // std::this_thread::sleep_for(std::chrono::milliseconds(100));

  // t1 = std::thread((LazyFoo()));
  // t2 = std::thread((LazyFoo()));
  // t1.join();
  // t2.join();
  // std::this_thread::sleep_for(std::chrono::milliseconds(100));

  t1 = std::thread((ThreadSafeLazyFoo()));
  t2 = std::thread((ThreadSafeLazyFoo()));
  t1.join();
  t2.join();
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  // t1 = std::thread((EagerFoo()));
  // t2 = std::thread((EagerFoo()));
  // t1.join();
  // t2.join();
}

int main() {
  std::cout << "hello lch" << std::endl;
  (void)SingletonTest();
  std::cout << "end lch" << std::endl;
  return 0;
}