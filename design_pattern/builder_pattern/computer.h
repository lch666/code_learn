// Computer.h
#pragma once
#include <string>

class Computer {
 public:
  // 可选的配件在构建对象的时候传入构造函数
  Computer(std::string cpu, std::string ram);
  // 直接配置的配件调用set函数设置
  void set_usb_count(int usb_count);
  void set_keyboard(std::string keyboard);
  void set_display(std::string display);
  // 打印对象信息的函数
  void to_string();
 private:
  // 可以供客户自己选配
  std::string cpu_; // cpu
  std::string ram_; // 内存
  // 剩下的配件不同厂商直接配置
  int usb_count_; // usb接口数量
  std::string keyboard_; // 键盘
  std::string display_; // 显示器
};