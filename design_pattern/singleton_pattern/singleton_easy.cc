#include <iostream>

class Csingleton {
private:
  Csingleton() = default;
  ~Csingleton() = default;
  static int temp;
public:
  static Csingleton* GetInstance() {
    static Csingleton singleton;
    return &singleton;
  }
  void Print() {
    std::cout << ++temp << std::endl;
  }
};
int Csingleton::temp = 0;


int main() {
  std::cout << "hello lch!" << std::endl;
  Csingleton::GetInstance()->Print();
  std::cout << Csingleton::GetInstance() << std::endl;
  Csingleton::GetInstance()->Print();
  std::cout << Csingleton::GetInstance() << std::endl;
  Csingleton::GetInstance()->Print();
  std::cout << Csingleton::GetInstance() << std::endl;
  Csingleton *c1 = Csingleton::GetInstance();
  c1->Print();
  std::cout << c1 << std::endl;
  std::cout << "end lch!" << std::endl;
  return 0;
}