/*
 * @Author: changheng.liu 
 * @Date: 2022-03-05 15:23:08 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-04-13 21:03:00
 */
#pragma once
#include  <vector>

namespace lch {
  class MergeSort {
    public:
      static const int a = 10;
    public:
      static void Sort(std::vector<int>& vec, int left, int right);
      static void Merge(std::vector<int>& vec, int left, int mid, int right);
  };
  void TestExtern();
}