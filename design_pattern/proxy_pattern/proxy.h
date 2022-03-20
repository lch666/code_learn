/*
 * @Author: changheng.liu 
 * @Date: 2022-03-05 15:23:08 
 * @Last Modified by:   changheng.liu 
 * @Last Modified time: 2022-03-05 15:23:08 
 */
#pragma once
#include <unistd.h>
#include <iostream>

class ImageSubject {
public:
  virtual void ShowImage() = 0;
};

class ImageReal : public ImageSubject {
public: 
  ImageReal() { sleep(3); std::cout << "Image Loading compete!" << std::endl; };
  void ShowImage() override { std::cout << "Show Real Image" << std::endl; };
};

class ProxyImage : public ImageReal {
public:
  ProxyImage(): real_image_(nullptr) {};
  void ShowImage() override { 
    if (nullptr == real_image_) {
      real_image_ = new ImageReal();
      real_image_->ShowImage();
    }
  };
private:
  ImageReal *real_image_;
};