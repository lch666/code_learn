#include <iostream>
#include <string>
#include <unistd.h>

std::string GetFilePath(const std::string& file_path,
                        const std::string& car_factory, const char& c) {
  std::string temp_path = file_path;
  int32_t num = temp_path.find_last_of(c);
  return temp_path.insert(num, "_" + car_factory);
}

int main(int argc, char **argv) {
  std::string path = "./demo";
  if (access(path.c_str(), F_OK) == 0) {
    std::cout << "dir exist" << std::endl;
  } else {
    std::cout << "not exist" << std::endl;
  }

  std::string name1 = "/abc/abc/hesr_conf/";
  std::string name2 = "/abc/abc/hesr_conf_net.hbm";
  std::string name3 = "/abc/abc/hisf.omi";
  
  std::cout << GetFilePath(name1, "CHERY_T18", '/') << std::endl;
  std::cout << GetFilePath(name2, "CHERY_T18", '_') << std::endl;
  std::cout << GetFilePath(name3, "CHERY_T18", '.') << std::endl;

  return 0;
}
