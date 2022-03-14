#include <iostream>
#include <queue>
#include <string>

void Test1() {
  std::cout << "------------------------------start Test1------------------------------" << std::endl;
  std::priority_queue<int> q1;  // 默认从大到小
  std::priority_queue<char, std::vector<char>, std::greater<char>> q2;  // 元素从大到小
  std::priority_queue<double, std::vector<double>, std::less<double>> q3;  // 元素从小到大

  for(int i = 0; i < 5; i++) {
    q1.push(2 * i - 3);
  }
  for(int i = 0; i < 5; i++) {
    q2.push('h' + 2 * i - 3);
  }
  for(int i = 0; i < 5; i++) {
    q3.push(8.8 + 2 * i - 1.1);
  }

  while(!q1.empty()) {
    std::cout << q1.top() << " ";
    q1.pop();
  }
  std::cout << std::endl;
  while(!q2.empty()) {
    std::cout << q2.top() << " ";
    q2.pop();
  }
  std::cout << std::endl;
  while(!q3.empty()) {
    std::cout << q3.top() << " ";
    q3.pop();
  }
  std::cout << std::endl;
  std::cout << "------------------------------end Test1------------------------------" << std::endl;
}

void Test2() {
  std::cout << "------------------------------start Test2------------------------------" << std::endl;
  std::queue<int> q;
  for (int i = 0; i < 8; i++) {
    q.push(i);
  }
  std::cout << "q front is " << q.front() << std::endl;
  std::cout << "q back is " << q.back() << std::endl;
  std::cout << "q size is " << q.size() << std::endl;
  std::cout << "q empty is " << q.empty() << std::endl;
  std::cout << "q emplace 10 " << std::endl; q.emplace(10);
  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
  std::queue<int> q1;
  q1.push(123);
  std::cout << "q swap q1" << std::endl;
  // q1.swap(q);
  std::swap(q, q1);
  std::cout << "q size is " << q.size() << std::endl;
  std::cout << "q1 size is " << q1.size() << std::endl;
  std::cout << "------------------------------end Test2------------------------------" << std::endl;
}

int main(int argc, char **argv) {
  std::cout << "hello lch !" << std::endl;
  (void)Test1();  // 优先队列
  (void)Test2();  // 普通队列
  std::cout << "end lch !" << std::endl;
}
