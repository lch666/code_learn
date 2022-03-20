/*
 * @Author: changheng.liu 
 * @Date: 2022-03-06 00:09:10 
 * @Last Modified by:   changheng.liu 
 * @Last Modified time: 2022-03-06 00:09:10 
 */
#include "proxy.h"
#include <iostream>
#include <memory>

class Text {
public:
  void ShowText() { std::cout << "now show text" << std::endl; };
};

class Docx {
public:
  Docx() {
    text_ = new Text();
    image_ = new ProxyImage();
  };
  void Show() { 
    std::cout << "now show text and image" << std::endl; 
    text_->ShowText();
    image_->ShowImage();
  };
  ~Docx() {
    delete image_;
    delete text_;
  }
private:
  Text *text_;
  ImageSubject *image_;
};

int main () {
  std::cout << "hello lch !" << std::endl;
  std::shared_ptr<Docx> docx = std::make_shared<Docx>();
  std::cout << "---------show start---------" << std::endl;
  docx->Show();
  std::cout << "---------show end---------" << std::endl;
  std::cout << "end lch !" << std::endl;
  return 0;
}