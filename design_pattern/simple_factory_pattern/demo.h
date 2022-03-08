/*
 * @Author: changheng.liu
 * @Date: 2022-03-05 15:24:19
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-03-05 15:59:38
 */
#pragma once

enum CarType {
  BMWCAR,
  BENZCAR
};

class Car {
private:
  /* data */
public:
  Car() = default;
  virtual ~Car() = default;
  virtual void Show() = 0;
};

class BmwCar : public Car {
private:
  /* data */
public:
  BmwCar() = default;
  ~BmwCar() = default;
  void Show() override;
};

class BenzCar : public Car {
private:
  /* data */
public:
  BenzCar() = default;
  ~BenzCar() = default;
  void Show() override;
};

class CarFactory {
private:
  /* data */
public:
  CarFactory() = default;
  ~CarFactory() = default;
  Car* CreateCar(CarType type);
};
