#include <iostream>
#include <vector>

class Car {

public:
  Car() {
    std::cout << "gao zao function" << std::endl;
  }

  void print() {
    std::cout << "test print function" << std::endl;
  }

  int add() {
    return a + b;
  }

private:
  char a;
  int b;
};

void TestVector() {
  std::vector<int> v;
  int size = -1;
  for (int i = 0; i < 100; i++) {
    if (v.capacity() != size) {
      std::cout << "size is " << v.size() << std::endl;
      size = v.capacity();
    }
    v.push_back(i);
  }
}

int main() {
  Car *car = nullptr;
  car->print();
  // std::cout << car->add() << std::endl;
  // (void) TestVector();
  std::cout << sizeof(Car) << std::endl;
}