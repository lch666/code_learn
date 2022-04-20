/*
 * @Author: changheng.liu 
 * @Date: 2022-04-13 20:00:00 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-04-13 21:03:19
 */

#include <iostream>
#include <vector>
#include "./sort/quick_sort.h"
#include "./sort/merge_sort.h"

#ifdef LCH_TEST
  int lch_max(int a, int b) {
    return a > b ? a : b;
  }
#endif

void Print(const std::vector<int>& vec) {
  for(const auto &it : vec) {
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
  std::cout << "------------- start test merge sort -------------" << std::endl;
  std::vector<int> vec(10);
  for (int i = 0; i < 10; i++) {
    vec[i] = std::rand() % 100;
  }
  std::cout << "before merge sort vec is " << std::endl;
  Print(vec);
  lch::MergeSort::Sort(vec, 0, vec.size() - 1);
  std::cout << "after merge sort vec is " << std::endl;
  Print(vec);
  std::cout << "------------- end test merge sort -------------" << std::endl;
}

void Test3() {
  std::cout << "------------- start test  -------------" << std::endl;
  std::cout << "lch::QuickSort::a is " << lch::QuickSort::a << std::endl;
  std::cout << "lch::MergeSort::a is " << lch::MergeSort::a << std::endl;
  std::cout << "test extern b is ";
  lch::TestExtern();
  std::cout << "------------- end test  -------------" << std::endl;
}

int main () {
  std::cout << "hello lch !" << std::endl;

  #ifdef LCH_TEST
  std::cout << lch_max(10, 20) << std::endl;
  #endif

  (void)Test1();
  (void)Test2();
  (void)Test3();
  
  std::cout << "end lch !" << std::endl;
  return 0;
}