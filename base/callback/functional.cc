#include <iostream>
#include <functional>

// https://www.cnblogs.com/bencai/p/9124654.html

int add(int a, int b) {
  return a + b;
}

class Base{
public:
  std::function<int(int, int)> func;  // 等同于函数指针
  int (*func1)(int, int);  // 函数指针
  std::function<void()> func2 = []() { std::cout << "test func2" << std::endl; };  // lambda表达式
  void Print(int num) { std::cout << "test print function " << num << std::endl; };  // 隐式传递了this指针，原型为void Print(Base *this, int num)

};

void TestFunction() {
  std::cout << "---------------------------start TestFunction---------------------------" << std::endl;
  Base base1; 
  base1.func = add;
  std::cout << base1.func(123, 234) << std::endl;
  base1.func1 = add;
  std::cout << base1.func1(123, 234) << std::endl;
  base1.func2();

  // std::function<void(const Base&, int)> func4 = Base::Print;
  // func4(base1, 123);

  std::function<void(const Base&, int)> func5 = std::bind(&Base::Print, &base1, 123);
  func5(base1, 123456);
  std::cout << "---------------------------start TestFunction---------------------------" << std::endl;
}

void TestBind() {
  std::cout << "---------------------------start TestBind---------------------------" << std::endl;
  auto func1 = std::bind(add, 123, 234);
  std::cout << func1() << std::endl;

  auto func2 = std::bind(add, std::placeholders::_1, 123);
  std::cout << func2(123) << std::endl;

  auto func3 = std::bind(add, std::placeholders::_1, std::placeholders::_2);
  std::cout << func3(123, 123) << std::endl;

  Base base;
  auto func4 = std::bind(&Base::Print, &base, std::placeholders::_1);
  func4(345);

  std::function<void(int)> func5 = std::bind(&Base::Print, &base, 123);
  func5(456);  // 依然输出123，填占位符才输出456
  std::cout << "---------------------------end TestBind---------------------------" << std::endl;
}

int main() {
  std::cout << "hello lch !" << std::endl;
  (void)TestFunction();
  (void)TestBind();
  std::cout << "end lch !" << std::endl;
  return 0;
}