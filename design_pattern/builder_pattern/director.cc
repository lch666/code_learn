// Director.cc
#include "./director.h"

void Director::makeComputer(ComputerBuilder *builder) {
  // Director类知道具体的部件如何组装
  builder->set_usb_count();
  builder->set_keyboard();
  builder->set_display();
}