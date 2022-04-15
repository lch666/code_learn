/*
 * @Author: changheng.liu 
 * @Date: 2022-04-13 20:00:00 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-04-13 21:03:19
 */

#include <iostream>
#include <vector>
#include "./quick_sort/quick_sort.h"

void Print(const std::vector<int>& vec) {
  for(auto &it : vec) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
}

void Test1() {
  std::cout << "------------- start test quick sort -------------" << std::endl;
  std::vector<int> vec(10);
  for (int i = 0; i < 10; i++) {
    vec[i] = std::rand() % 100;
  }
  std::cout << "before quick sort vec is " << std::endl;
  Print(vec);
  lch::QuickSort::Sort(vec, 0, vec.size() - 1);
  std::cout << "after quick sort vec is " << std::endl;
  Print(vec);
  std::cout << "------------- end test quick sort -------------" << std::endl;
}

void Test2() {
  std::cout << "------------- start test  sort -------------" << std::endl;

  std::cout << "------------- end test  sort -------------" << std::endl;
}

#define LCH_TEST

int main () {
  std::cout << "hello lch !" << std::endl;

  (void) Test1();
  (void) Test2();
  
  std::cout << "end lch !" << std::endl;
  return 0;
}