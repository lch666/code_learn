#include <iostream>
#include <sstream>

template<typename T>
std::string ToString(const T& temp) {
  std::ostringstream stm;
  stm << temp;
  return stm.str();
}

template<typename T>
void PrintTest(const T& temp) {
  std::cout << temp << std::endl;
}

template<typename T, typename... Args>
void PrintTest(const T& temp, const Args &... args) {
  std::cout << temp << std::endl;
  PrintTest(args...);     // 大于两个参数递归调用自己，最后一个参数调用重载模板函数PrintTest(const T& temp)
}

int main() {
  std::cout << "hello lch!" << std::endl;

  int32_t temp1 = 1021;
  std::string ret1 = ToString(temp1);
  std::cout << ret1 << std::endl;

  PrintTest<std::string, int>("horizon", 110, 120, 32.44, 'a',  "test is end");
  std::cout << "end lch!" << std::endl;
  return 0;
}