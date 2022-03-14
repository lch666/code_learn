#include <iostream>

// 构造函数与赋值运算符的区别是，构造函数在创建或初始化对象的时候调用，而赋值运算符在更新一个对象的值时调用
// 对象不存在，且没用别的对象来初始化，就是调用了构造函数
// 对象不存在，且用别的对象来初始化，就是拷贝构造函数
// 对象存在，用别的对象来给它赋值，就是赋值函数
// https://www.cnblogs.com/hunter-w/p/13884186.html

class Base {
private:
  int var_;
  std::string name_;
public:
  Base(int var, std::string name) : var_(var), name_(name) { std::cout << name_ << " 构造函数" << std::endl; };
  Base(const Base& base) : var_(base.var_), name_(base.name_) { std::cout << name_ << " 拷贝构造函数" << std::endl; };
  Base& operator=(const Base& base) { std::cout << base.name_ << " 赋值函数" << std::endl;  var_ = base.var_ ; name_ = base.name_;   return *this; };
  Base(Base&& base) : var_(base.var_), name_(base.name_) { std::cout << name_ << " 移动构造函数" << std::endl; };
  Base& operator= (Base&& base) { std::cout << base.name_ << " 移动赋值函数" << std::endl; var_ = base.var_; name_ = base.name_;  return *this; };
  ~Base() { std::cout << name_ << " 析构函数" << std::endl; };
};

Base GetBase() {
  return Base(100, "test");
}

Base&& MoveBase(Base& base) {
  return std::move(base);
}

int main () {
  std::cout << "hello lch ! " << std::endl;
  std::cout << "-----------------------------1-----------------------------" << std::endl;
  Base base1(10, "base1");  // 构造函数
  std::cout << "-----------------------------2-----------------------------" << std::endl;
  Base base2 = base1;  // 拷贝构造函数
  std::cout << "-----------------------------3-----------------------------" << std::endl;
  Base base3(base1);  // 拷贝构造函数
  std::cout << "-----------------------------4-----------------------------" << std::endl;
  base2 = base1;  // 赋值函数
  std::cout << "-----------------------------5-----------------------------" << std::endl;
  Base base4 = Base(20, "base4");  // 构造函数
  std::cout << "-----------------------------6-----------------------------" << std::endl;
  Base base5 = std::move(base1);  // 移动构造函数
  std::cout << "-----------------------------7-----------------------------" << std::endl;
  Base base6 = GetBase();  // 构造函数
  std::cout << "-----------------------------8-----------------------------" << std::endl;
  Base&& base7 = MoveBase(base6);
  std::cout << "-----------------------------9-----------------------------" << std::endl;
  base4 = Base(30, "base4");  // 构造函数 移动赋值函数 析构函数
  std::cout << "-----------------------------10-----------------------------" << std::endl;
  std::cout << "end lch !" << std::endl;
  return 0;
}