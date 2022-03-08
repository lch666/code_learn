#include "demo.h"
#include <iostream>

void BmwCar::Show() {
  std::cout << "now car show is bmw !" << std::endl;
}

void BenzCar::Show() {
  std::cout << "now car show is benz !" << std::endl;
}

Car* CarFactory::CreateCar(CarType type) {
  switch (type) {
    case BMWCAR:
      return new BmwCar();
      break;
    case BENZCAR:
      return new BenzCar();
    default:
      return nullptr;
      break;
  }
} 

int main () {
  std::cout << "hello lch !" << std::endl;

  CarFactory factory;

  Car *benz_car = factory.CreateCar(BENZCAR);
  if (nullptr != benz_car) {
    benz_car->Show();
    delete benz_car;
    benz_car = nullptr;
  }

  Car *bmw_car = factory.CreateCar(BMWCAR);
  if (nullptr != bmw_car) {
    bmw_car->Show();
    delete bmw_car;
    bmw_car = nullptr;
  }

  std::cout << "end lch !" << std::endl;
  return 0;
}