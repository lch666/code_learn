// Builder.h
#pragma once
#include "./computer.h"
// 抽象的builder接口
class ComputerBuilder {
 public:
  virtual void set_usb_count() = 0;
  virtual void set_keyboard() = 0;
  virtual void set_display() = 0;
  // 返回computer的接口
  virtual Computer* getComputer() = 0;
};

// 具体的建造者类MacBuilder，苹果电脑制造商
class MacBuilder : public ComputerBuilder {
 public:
  // 给了cpu和内存 两个 默认值
  MacBuilder(std::string cpu = "i5", std::string ram = "三星16G");
  ~MacBuilder();
  // 具体实现接口函数
  void set_usb_count() final;
  void set_keyboard() final;
  void set_display() final;
  Computer* getComputer() final;

 private:
  // 具体建造者类依赖于具体的产品类
  Computer* computer_;
};

// 具体的建造者类HpBuilder，Hp电脑制造商
class HpBuilder : public ComputerBuilder {
 public:
  HpBuilder(std::string cpu = "i7", std::string ram = "海力士16G");
  ~HpBuilder();
  void set_usb_count() final;
  void set_keyboard() final;
  void set_display() final;
  Computer* getComputer() final;

 private:
  Computer* computer_;
};