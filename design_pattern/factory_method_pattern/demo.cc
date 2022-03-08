#include "demo.h"
#include <iostream>

void BmwCar::Show() {
  std::cout << "now car show is bmw !" << std::endl;
}

void BenzCar::Show() {
  std::cout << "now car show is benz !" << std::endl;
}

Car* BmwFactory::CreateCar() {
  return new BmwCar();
}

Car* BenzFactory::CreateCar() {
  return new BenzCar();
}

int main () {
  std::cout << "hello lch !" << std::endl;

  CarFactory *factory; 
  Car *car;

  factory = new BmwFactory();
  car = factory->CreateCar();
  (void)car->Show();
  delete factory;
  delete car;

  factory = new BenzFactory();
  car = factory->CreateCar();
  (void)car->Show();
  delete factory;
  delete car;
  factory = nullptr;
  car = nullptr;

  std::cout << "end lch !" << std::endl;
  return 0;
}