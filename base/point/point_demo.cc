#include<iostream>
#include<memory>

void Test1() {
  std::cout << "------------------------------end Test1------------------------------" << std::endl;
  std::shared_ptr<int> p1(new int(100));
  std::cout << *p1 << std::endl;
  std::cout << p1.use_count() << std::endl;
  std::cout << p1.unique() << std::endl;

  std::weak_ptr<int> p2(p1);
  std::cout << p2.use_count() << std::endl;

  std::unique_ptr<std::string> p3(new std::string("happy"));
  std::cout << *p3 << std::endl;

  std::cout << "end lch!" << std::endl;
  std::cout << "------------------------------end Test1------------------------------" << std::endl;
}

void Test2() {
  std::cout << "------------------------------end Test2------------------------------" << std::endl;
  int x = 1024;
  int *p1 = &x;
  int **p2 = &p1;
  int ***p3 = &p2;

  std::cout << "&x = " << &x << std::endl;
  std::cout << "p1 = " << p1 << std::endl;
  std::cout << "*p1 = " << *p1 << std::endl;
  std::cout << "p2 = " << p2 << std::endl;
  std::cout << "*p2 = " << *p2 << std::endl;
  std::cout << "p3 = " << p3 << std::endl;
  std::cout << "*p3 = " << *p3 << std::endl;
  std::cout << "sizeof int x is " << sizeof(x) << std::endl;
  std::cout << "sizeof p1 is " << sizeof(p1) << std::endl;
  std::cout << "sizeof p2 is " << sizeof(p2) << std::endl;
  std::cout << "sizeof p3 is " << sizeof(p3) << std::endl;
  std::cout << "------------------------------end Test2------------------------------" << std::endl;
}

int main() {
  std::cout << "hello lch!" << std::endl;
  (void)Test1();
  (void)Test2();
  std::cout << "end lch!" << std::endl;
  return 0;
}