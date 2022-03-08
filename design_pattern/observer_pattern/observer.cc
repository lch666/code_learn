/*
 * @Author: changheng.liu 
 * @Date: 2022-03-06 23:07:43 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-03-08 10:20:00
 */
#include "observer.h"
#include <iostream>
#include <string>

int Observer::static_number_ = 0;

void Observer::Update(const std::string &message) {
  this->message_ = message;
  std::cout << "observer number is " << this->number_
            << " is subcribe, message is " << this->message_ << std::endl;
}

void Observer::Subscirbe(Subject *subject) {
  this->subject_ = subject;
  this->subject_->Attach(this);
  std::cout << "this is observer " << ++Observer::static_number_ << std::endl;
  this->number_ = Observer::static_number_;
}

void Observer::UnSubscirbe() {
  this->subject_->Detach(this);
  std::cout << "observer number " << number_ << " is unsbscribe" <<std::endl;
}



void Subject::Attach(AbstractObserver *Observer) {
  list_observer_.push_back(Observer);
}

void Subject::Detach(AbstractObserver *Observer) {
  list_observer_.remove(Observer);
}

void Subject::Notify() {
  auto iterator = list_observer_.begin();
  std::cout << "list observer size is " << list_observer_.size() << std::endl;
  while (iterator != list_observer_.end()) {
    (*iterator)->Update(message_);
    ++iterator;
  }
}

void Subject::CreateMessage(std::string message) {
  this->message_ = message;
  Notify();
}