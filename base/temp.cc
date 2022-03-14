#include <iostream>
#include <string>

void Test1() {
  std::cout << "------------------------------start Test1------------------------------" << std::endl;

  std::cout << "------------------------------end Test1------------------------------" << std::endl;
}

int main(int argc, char **argv) {
  std::cout << "hello lch !" << std::endl;
  (void)Test1();
  std::cout << "end lch !" << std::endl;
}
