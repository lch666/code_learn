/*
 * @Author: changheng.liu 
 * @Date: 2022-03-06 00:09:10 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-04-13 21:03:56
 */
#include "./quick_sort.h"
#include <iostream>
int b = 200;
namespace lch {
  void QuickSort::Sort(std::vector<int>& vec, int left, int right) {
    if (left >= right) return;
    int l = left, r = right, key = vec[left];
    while(l < r) {
      while (vec[r] >= key && l < r) --r;
      if (l < r) vec[l++] = vec[r];
      while (vec[l] < key && l < r) ++l;
      if (l < r) vec[r--] = vec[l];
    }
    vec[l] = key;
    Sort(vec, left, l - 1);
    Sort(vec, l + 1, right);
  }
}