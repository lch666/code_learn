/*
 * @Author: changheng.liu
 * @Date: 2022-03-05 15:24:19
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-03-06 01:12:26
 */
#pragma once
#include <iostream>

class Car {
public:
  Car() { std::cout << "Car()" << std::endl; }
  virtual ~Car() { std::cout << "~Car()" << std::endl; }
  virtual void Show() = 0;
};

class BmwCar : public Car {
public:
  BmwCar() { std::cout << "BmwCar()" << std::endl; }
  ~BmwCar(){ std::cout << "~BmwCar()" << std::endl; }
  void Show() override;
};

class BenzCar : public Car {
public:
  BenzCar() { std::cout << "BenzCar()" << std::endl; }
  ~BenzCar() { std::cout << "~BenzCar()" << std::endl; }
  void Show() override;
};

class CarFactory {
public:
  CarFactory() { std::cout << "CarFactory()" << std::endl; }
  virtual ~CarFactory() { std::cout << "~CarFactory()" << std::endl; }
  virtual Car* CreateCar() = 0;
};

class BmwFactory : public CarFactory {
public:
  BmwFactory() { std::cout << "BmwFactory()" << std::endl; }
  ~BmwFactory() { std::cout << "~BmwFactory()" << std::endl; }
  Car* CreateCar();
};

class BenzFactory : public CarFactory {
public:
  BenzFactory() { std::cout << "BenzFactory()" << std::endl; }
  ~BenzFactory() { std::cout << "~BenzFactory()" << std::endl; }
  Car* CreateCar();
};