// Director.h
#pragma once

#include "./builder.h"

// 构建使用builder接口的对象
class Director {
 public:
  void makeComputer(ComputerBuilder *builder);
};