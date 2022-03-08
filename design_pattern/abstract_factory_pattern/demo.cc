#include "factory.h"
#include <iostream>

int main () {
  std::cout << "hello lch !" << std::endl;

  CarFactory *factory;
  SoftWare *software;
  HardWare *hardware;  

  // bmw factory
  factory = new BmwFactory();
  software = factory->CreateSoftWare();
  hardware = factory->CreateHardWare();
  software->Show();
  hardware->Show();
  delete factory;
  delete software;
  delete hardware;
  
  // benz factory
  factory = new BenzFactory();
  software = factory->CreateSoftWare();
  hardware = factory->CreateHardWare();
  software->Show();
  hardware->Show();
  delete factory;
  delete software;
  delete hardware;

  std::cout << "end lch !" << std::endl;
  return 0;
}