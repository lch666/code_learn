/*
 * @Author: changheng.liu 
 * @Date: 2022-03-05 22:28:33 
 * @Last Modified by:   changheng.liu 
 * @Last Modified time: 2022-03-05 22:28:33 
 */

#include "product.h"
#include <iostream>

void BmwHardWare::Show() {
  std::cout << "now execute bmw hardware !" << std::endl;
}

void BenzHardWare::Show() {
  std::cout << "now execute benz hardware !" << std::endl;
}

void BmwSoftWare::Show() {
  std::cout << "now execute bmw softWare !" << std::endl;
}

void BenzSoftWare::Show() {
  std::cout << "now execute benz softWare !" << std::endl;
}