// Builder.cc
#include "./builder.h"

MacBuilder::MacBuilder(std::string cpu, std::string ram) {
  computer_ = new Computer(cpu, ram);
}
MacBuilder::~MacBuilder() { delete computer_; }
void MacBuilder::set_usb_count() { computer_->set_usb_count(3); }
void MacBuilder::set_keyboard() { computer_->set_keyboard("Apple键盘"); }
void MacBuilder::set_display() { computer_->set_display("Apple显示器"); }
Computer* MacBuilder::getComputer() { return computer_; }

HpBuilder::HpBuilder(std::string cpu, std::string ram) {
  computer_ = new Computer(cpu, ram);
}
HpBuilder::~HpBuilder() { delete computer_; }
void HpBuilder::set_usb_count() { computer_->set_usb_count(4); }
void HpBuilder::set_keyboard() { computer_->set_keyboard("Hp键盘"); }
void HpBuilder::set_display() { computer_->set_display("Hp显示器"); }
Computer* HpBuilder::getComputer() { return computer_; }