#include <iostream>
#include <memory>
using namespace std;
class CarBase {
private:
  std::string car_name_;
public:
  CarBase() {};
  ~CarBase() {};
  void SetCarBaseName(std::string car_name);
  std::string GetCarBaseName();
};

void CarBase::SetCarBaseName(std::string car_name) {
  car_name_ = car_name;
}

std::string CarBase::GetCarBaseName() {
  return car_name_;
}

int main() {
  std::cout << "hello lch!" << std::endl;

  CarBase *car1 = new CarBase();
  car1->SetCarBaseName("baoma");
  std::cout << car1->GetCarBaseName() << std::endl;

  CarBase car2;
  car2.SetCarBaseName("benchi");
  std::cout << car2.GetCarBaseName() << std::endl;

  std::shared_ptr<CarBase> car3 = std::make_shared<CarBase>();
  car3->SetCarBaseName("aodi");
  std::cout << car3->GetCarBaseName() << std::endl;
  std::cout << car3.use_count() << std::endl;

  auto car4(car3);
  std::cout << car3.use_count() << std::endl;
  std::cout << car4.use_count() << std::endl;

  std::shared_ptr<CarBase> car5(new CarBase());
  car5->SetCarBaseName("tesla");
  std::cout << car5->GetCarBaseName() << std::endl;

  std::cout << "end lch!" << std::endl;
  return 0;
}