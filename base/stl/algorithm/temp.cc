#include <iostream>
#include <string>
#include <algorithm>

void Test1() {
  std::cout << "------------------------------start Test1------------------------------" << std::endl;

  std::cout << "------------------------------end Test1------------------------------" << std::endl;
}

void Test2() {
  std::cout << "------------------------------start Test2------------------------------" << std::endl;

  std::cout << "------------------------------end 2------------------------------" << std::endl;
}

int main(int argc, char **argv) {
  std::cout << "hello lch !" << std::endl;
  (void)Test1();
  (void)Test2();
  std::cout << "end lch !" << std::endl;
}
