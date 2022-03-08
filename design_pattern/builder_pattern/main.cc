// main.cc
#include "./director.h"

int main() {
  Director *director = new Director();
  MacBuilder *mac = new MacBuilder();
  HpBuilder *hp = new HpBuilder();
  director->makeComputer(mac);
  director->makeComputer(hp);
  (void)mac->getComputer()->to_string();
  (void)hp->getComputer()->to_string();
  delete hp;
  delete mac;
  delete director;
  return 0;
}