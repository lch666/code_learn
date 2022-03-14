#include <iostream>

int add(int a, int b) {
  return a + b;
}

class Base{
public:
  int (*fun)(int a, int b) {};  // 函数指针
  int* fun1(int *a, int b) {  // 指针函数
    *a = *a + b;
    return a;
  }
};



int main() {
  std::cout << "hello lch !" << std::endl;
  Base base1;
  base1.fun = add;
  std::cout << base1.fun(101, 202) << std::endl;

  int a = 10;
  int *res = base1.fun1(&a, 34);
  std::cout << *res << std::endl;
  std::cout << res << std::endl;
  std::cout << "end lch !" << std::endl;
  return 0;
}