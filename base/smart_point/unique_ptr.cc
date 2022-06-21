#include <iostream>
#include <memory>
#include <iostream>

// https://blog.csdn.net/Cdreamfly/article/details/123338341
// https://blog.csdn.net/m0_38076911/article/details/107071926?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-107071926-blog-102688577.pc_relevant_antiscanv2&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-107071926-blog-102688577.pc_relevant_antiscanv2&utm_relevant_index=1

template <typename T>
class unique_ptr {
 public:
  constexpr unique_ptr() noexcept : ptr_(nullptr) {}
  constexpr unique_ptr(nullptr_t) noexcept : unique_ptr() {}  // typedef decltype(nullptr) nullptr_t;
  explicit unique_ptr(T *ptr) noexcept : ptr_(ptr) {}
  ~unique_ptr() noexcept { delete ptr_; }
  unique_ptr(const unique_ptr &) = delete;  // 禁用拷贝构造函数
  unique_ptr& operator=(const unique_ptr &) = delete;  // 禁用赋值函数
  unique_ptr(unique_ptr &&other) noexcept : ptr_(other.release()) {}
  unique_ptr &operator=(unique_ptr &&other) noexcept {
    this->reset(other.release());
    return *this;
  }
  unique_ptr &operator=(nullptr_t) {
    this->reset();
    return *this;
  }
  T& operator*() const noexcept { return *ptr_; }
  T* operator->() const noexcept { return ptr_; }
  T* release() noexcept {  // return std::exchange(ptr_, nullptr); // C++14用法
    T* temp = ptr_;
    ptr_ = nullptr;
    return temp;
  }
  void reset(T *ptr) noexcept {  // return std::exchange(ptr_, ptr); // C++14用法
    ptr_ = ptr;
  }
  T* get() const noexcept { return ptr_; }
  void swap(unique_ptr &other) noexcept { std::swap(ptr_, other.ptr_); };
  operator bool() const noexcept { return static_cast<bool>(ptr_); }
  void test_print() { std::cout << "test number is " << ++num << std::endl; }
 private:
  T *ptr_;
  static int num;
};

template <typename T>
int unique_ptr<T>::num = 0;

template <typename T, typename... Args>
auto make_unique(Args &&... args) {
  return unique_ptr<T>(new T(std::forward(args)...));
}

int main() {
  std::cout << "hello lch !!!" << std::endl;
  unique_ptr<int> ptr(new int (100));
  std::cout << &ptr << std::endl;
  std::cout << *ptr << std::endl;
  std::cout << bool(ptr) << std::endl;
  (void)ptr.test_print();

  unique_ptr<int> ptr1;
  std::cout << bool(ptr1) << std::endl;
  ptr1 = make_unique<int>();
  *ptr1 = 200;
  std::cout << &ptr1 << std::endl;
  std::cout << *ptr1 << std::endl;
  std::cout << bool(ptr1) << std::endl;
  (void)ptr1.test_print();

  unique_ptr<int> *ptr2 = new unique_ptr<int>();
  std::cout << &ptr2 << std::endl;
  std::cout << *ptr2 << std::endl;
  (void)ptr2->test_print();
  std::cout << "end lch !!!" << std::endl;
  return 0;
}

