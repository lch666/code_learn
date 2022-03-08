/*
 * @Author: changheng.liu 
 * @Date: 2022-03-06 22:51:11 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-03-08 10:11:40
 */
#pragma once
#include <string>
#include <list>

class AbstractObserver {
public:
  AbstractObserver() = default;
  virtual ~AbstractObserver() = default;
  virtual void Update(const std::string& message) = 0;
};

class AbstractSubject {
public:
  AbstractSubject() = default;
  virtual ~AbstractSubject() = default;
  virtual void Attach(AbstractObserver *observer) = 0;
  virtual void Detach(AbstractObserver *observer) = 0;
  virtual void Notify() = 0;
};

class Subject : public AbstractSubject {
public:
  Subject() = default;
  ~Subject() = default;
  void Attach(AbstractObserver *Observer) override;
  void Detach(AbstractObserver *Observer) override;
  void Notify() override;
  void CreateMessage(std::string message = "empty");
private:
  std::list<AbstractObserver *> list_observer_;
  std::string message_;
};

class Observer : public AbstractObserver {
public:
  Observer() = default;
  ~Observer() = default;
  void Update(const std::string& message) override;
  void Subscirbe(Subject *subject);
  void UnSubscirbe();
private:
  std::string message_;
  Subject *subject_;
  int number_;
  static int static_number_;
};

