/*
 * @Author: changheng.liu 
 * @Date: 2022-03-07 21:13:54 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-03-08 10:18:13
 */

#include "./observer.h"
#include <iostream>
#include <memory>

void ObserverTest() {
  Subject *subject = new Subject();
  Observer *observer1 = new Observer();
  Observer *observer2 = new Observer();
  Observer *observer3 = new Observer();
  observer1->Subscirbe(subject);
  observer2->Subscirbe(subject);
  observer3->Subscirbe(subject);
  subject->CreateMessage("this is first message");
  std::shared_ptr<Observer> observer4 = std::make_shared<Observer>();
  observer4->Subscirbe(subject);
  observer2->UnSubscirbe();
  observer3->UnSubscirbe();
  subject->CreateMessage("this is secode message");
}

int main() {
  std::cout << "hello lch !" << std::endl;
  (void)ObserverTest();
  std::cout << "end lch !" << std::endl;
  return 0;
}