// Computer.cc
#include "./computer.h"

#include <iostream>

Computer::Computer(std::string cpu, std::string ram) {
  this->cpu_ = cpu;
  this->ram_ = ram;
}
void Computer::set_usb_count(int usb_count) { usb_count_ = usb_count; }
void Computer::set_keyboard(std::string keyboard) { keyboard_ = keyboard; }
void Computer::set_display(std::string display) { display_ = display; }
void Computer::to_string() {
  std::cout << "cpu: " << cpu_ << " ,ram: " << ram_
            << " ,usb_count: " << usb_count_ << " ,keyboard: " << keyboard_
            << " ,display : " << display_ << std::endl;
}