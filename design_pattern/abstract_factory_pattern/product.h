/*
 * @Author: changheng.liu 
 * @Date: 2022-03-05 15:23:08 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-03-05 22:26:32
 */
#pragma once

class HardWare {
public:
  HardWare() = default;
  virtual ~HardWare() = default; 
  virtual void Show() = 0;
};

class BmwHardWare : public HardWare {
public:
  BmwHardWare() = default;
  ~BmwHardWare() = default;
  void Show() override;
};

class BenzHardWare : public HardWare {
public:
  BenzHardWare() = default;
  ~BenzHardWare() = default;
  void Show() override;
};

class SoftWare {
public:
  SoftWare() = default;
  virtual ~SoftWare() = default; 
  virtual void Show() = 0;
};

class BmwSoftWare : public SoftWare {
public:
  BmwSoftWare() = default;
  ~BmwSoftWare() = default;
  void Show() override;
};

class BenzSoftWare : public SoftWare {
public:
  BenzSoftWare() = default;
  ~BenzSoftWare() = default;
  void Show() override;
};
