/*
 * @Author: changheng.liu 
 * @Date: 2022-03-05 22:28:44 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-03-05 23:44:00
 */

#pragma once
#include "./product.h"

class CarFactory {
public:
  CarFactory() = default;
  virtual ~CarFactory() = default; 
  virtual SoftWare* CreateSoftWare() = 0;
  virtual HardWare* CreateHardWare() = 0;
};

class BmwFactory : public CarFactory {
public:
  BmwFactory() = default;
  ~BmwFactory() = default;
  SoftWare* CreateSoftWare();
  HardWare* CreateHardWare();
};

class BenzFactory : public CarFactory {
public:
  BenzFactory() = default;
  ~BenzFactory() = default;
  SoftWare* CreateSoftWare();
  HardWare* CreateHardWare();
};
