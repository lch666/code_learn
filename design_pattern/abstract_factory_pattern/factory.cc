/*
 * @Author: changheng.liu 
 * @Date: 2022-03-05 22:28:53 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-03-05 23:36:57
 */

#include "factory.h"

SoftWare* BmwFactory::CreateSoftWare() {
  return new BmwSoftWare();
}

HardWare* BmwFactory::CreateHardWare() {
  return new BmwHardWare();
}

SoftWare* BenzFactory::CreateSoftWare() {
  return new BenzSoftWare();
}

HardWare* BenzFactory::CreateHardWare() {
  return new BenzHardWare();
}