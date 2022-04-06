#include <iostream>
#include <stack>
#include <string>

class Base {

};

class Base1 {
public:
  virtual void Print1() {};
  virtual void Print2() {};
};

class Base2 {
public:
  virtual void Print3() {};
};

class TestBase : public Base1, public Base2, public Base{
public:
  void Print1() override;
  void Print2() override {};
  void Print3() override {};
};

void TestBase::Print1() {
  std::cout << "test" << std::endl;
}


class MinStack {
public:
  std::stack<int> s, min_s;
  MinStack() {}
  
  void push(int val) {
      s.push(val);
      if ((!min_s.empty() && val <= min_s.top()) || min_s.empty()) min_s.push(val);  // min_s空和非空（重复元素需<=）
  }
  
  void pop() {
      int x = s.top();
      s.pop();
      if (x == min_s.top()) min_s.pop();
  }
  
  int top() {
      return s.top();
  }
  
  int getMin() {
      if (min_s.empty()) return s.top();
      return min_s.top();
  }
};

void Test1() {   // 最小栈的实现
  std::cout << "------------------------------start Test1------------------------------" << std::endl;
  MinStack minStack;
  Base base;
  Base1 base1;
  Base1 base2;
  TestBase test_base;
  std::cout << "sizeof(minStack) is " << sizeof(minStack) << std::endl;
  std::cout << "sizeof(base) is " << sizeof(base) << std::endl;
  std::cout << "sizeof(base1) is " << sizeof(base1) << std::endl;
  std::cout << "sizeof(base2) is " << sizeof(base2) << std::endl;
  std::cout << "sizeof(test_base) is " << sizeof(test_base) << std::endl;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  std::cout << "get min is " << minStack.getMin() << std::endl;   // 返回 -3.
  minStack.pop();
  minStack.top();      // 返回 0.
  std::cout << "get min is " << minStack.getMin() << std::endl;   // 返回 -2.

  std::cout << "------------------------------end Test1------------------------------" << std::endl;
}



int main(int argc, char **argv) {
  std::cout << "hello lch !" << std::endl;
  (void)Test1();  // 最小栈
  std::cout << "end lch !" << std::endl;
}
