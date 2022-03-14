#include <iostream>
#include <memory>

template <typename T>
class shared_ptr {
private:
  int *count_;
  T *ptr_;
public:
  shared_ptr(T *p) : count_(new int (1)), ptr_(p) {} // 构造函数
  shared_ptr(shared_ptr<T>& other) : count_(&(++*other.count_)), ptr_(other.ptr_) {} // 拷贝构造函数
  T* operator->() { return ptr_; } // 重载->
  T& operator*() { return *ptr_; }  // 重载*
  shared_ptr<T>& operator=(shared_ptr<T>& other) {  // 赋值函数
    ++*other.count_;
    if (this->ptr_ && 0 == --*this->count_) {
      delete count_;
      delete ptr_;
    }
    this->ptr_ = other.ptr_;
    this->count_ = other.count_;
    return *this;
  }
  ~shared_ptr() {   // 析构函数
    if (--*count_ == 0) {
      delete count_;
      delete ptr_;
    }
  }
  int use_count() { return *count_; }
};

int main() {
  std::cout << "hello lch!" << std::endl;

  shared_ptr<int> temp1(new int(100));
  shared_ptr<int> temp2(temp1);  
  std::cout << temp1.use_count() << std::endl;
  std::cout << temp2.use_count() << std::endl;
  std::cout << *temp1 << std::endl;
  std::cout << *temp2 << std::endl;

  std::shared_ptr<int> temp3(new int (200));
  std::cout << temp3.use_count() << std::endl;
  std::cout << *temp3 << std::endl;

  std::cout << "end lch!" << std::endl;
  return 0;
}