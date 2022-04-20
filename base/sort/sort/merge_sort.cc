/*
 * @Author: changheng.liu 
 * @Date: 2022-03-06 00:09:10 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-04-13 21:03:56
 */
#include "./merge_sort.h"
#include <iostream>
extern int b;
namespace lch {
  void MergeSort::Sort(std::vector<int>& vec, int left, int right) {
    if (vec.empty() || left >= right) {
      return;
    }
    int mid = (left + right) >> 1;
    Sort(vec, left, mid);
    Sort(vec, mid + 1, right);
    Merge(vec, left, mid, right);
  }

  void MergeSort::Merge(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int first = left;
    int second = mid + 1;
    int index = 0;
    while (first <= mid && second <= right) {
      if (vec[first] <= vec[second]) {
        temp[index++] = vec[first++];
      } else {
        temp[index++] = vec[second++];
      }
    }
    while (first <= mid) {
      temp[index++] = vec[first++];
    }
    while (second <= right) {
      temp[index++] = vec[second++];
    }
    for (int i = 0; i < index; i++) {
      vec[left + i] = temp[i];
    }
  }

  void TestExtern() {
    std::cout << b << std::endl;
  }
}