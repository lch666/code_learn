#include <iostream>
#include <string>
#include <cmath>      // std::pow
#include <climits>    // INT_MAX
#include <map>
#include <algorithm>

void Print(std::pair<int, std::string> t) {
  std::cout << t.first << " " << t.second << std::endl;
}

void Test1(const std::map<int, std::string>& m) {
  std::cout << "------------------------------start Test1------------------------------" << std::endl;
  // 遍历方式1
  std::cout << "traverse map first" << std::endl;
  for (auto it : m) {
    std::cout << it.first << " " << it.second << " " << std::endl;
  }

  // 遍历方式2 for_each头文件为algorithm
  std::cout << "traverse map second" << std::endl;
  for_each(m.begin(), m.end(), [](const std::pair<int, std::string>& it) {
    std::cout << it.first << " " << it.second << " " << std::endl;
  });

  // 遍历方式3
  std::cout << "traverse map third" << std::endl;
  for_each(m.begin(), m.end(), Print);

  // 遍历方式4
  std::cout << "traverse map fourth" << std::endl;
  for (auto it = m.begin(); it != m.end(); ++it) {
    std::cout << it->first << " " << it->second << " " << std::endl;
  }

  // 遍历方式5
  std::cout << "traverse map fifth" << std::endl;
  std::map<int, std::string>::const_iterator iter = m.begin();
  std::map<int, std::string>::const_iterator iter_const = m.cbegin();  // 返回const迭代器
  while (iter_const != m.cend()) {
    std::cout << iter_const->first << " " << iter_const->second << " " << std::endl;
    ++iter_const;
  }
  std::cout << "------------------------------end Test1------------------------------" << std::endl;
}

void Test2(const std::map<int, std::string>& m) {
  std::cout << "------------------------------start Test2------------------------------" << std::endl;
  std::map<int, std::string> mm;

  if (m.count(6) > 0) {  // map不包含重复元素，值为0或者1；查找效率低，先count,再find
    std::cout << "m.count(6) is " << m.count(6) << std::endl;
    std::cout << "m.at(6) is " << m.at(6) << std::endl; 
  }
  
  auto iter1 = m.find(3);  // find返回迭代器,可直接输出second的值
  if (iter1 != m.end()) {
    std::cout << "m.find(3) iter1->first is " << iter1->second << "iter->second is " << iter1->second << std::endl;
  } else {
    std::cout << "map m not find index 3" << std::endl;
  }

  std::cout << "map empty is " << m.empty() << std::endl;
  std::cout << "map size is " << m.size() << std::endl;
  std::cout << "------------------------------end Test2------------------------------" << std::endl;
}

void Test3(std::map<int, std::string>& m) {
  std::cout << "map count 3 is " << m.count(3) << std::endl;
  std::cout << "map key 3 is " << m[3] << std::endl;
  std::cout << "map erase 3 " << std::endl;
  m.erase(3);
  std::cout << "map count 3 is " << m.count(3) << std::endl;
  std::cout << "map size is " << m.size() << std::endl;
  std::cout << "map insert 10, ten" << std::endl;
  m.insert({10, "ten"});
  std::cout << "map emplace 11, eleven" << std::endl;
  m.emplace(11, "eleven");
  std::cout << "map size is " << m.size() << std::endl;
  std::cout << "map max size is " << m.max_size() << std::endl;
  std::cout << "INT_MAX is " << INT_MAX << std::endl;
  std::cout << "2^31 - 1 is " << std::pow(2, 31) - 1 << std::endl;
  std::cout << "map lower_bound 3" << std::endl;
  auto it = m.lower_bound(3);
  std::cout << "iter first is " << it->first << " iter second is " << it->second << std::endl;
  std::cout << "map upper_bound 4" << std::endl;
  it = m.lower_bound(4);
  std::cout << "iter first is " << it->first << " iter second is " << it->second << std::endl;
  auto rit = m.rbegin();
  std::cout << "rbegin first is " << rit->first << " rend second is " << rit->second << std::endl;
  rit = m.rend();  // begin的前一个，无效值
  std::cout << "rend first is " << rit->first << " rend second is " << rit->second << std::endl;

  std::map<int, std::string> temp;
  temp[100] = "test";
  m.swap(temp);  // 对象互换
  std::cout << "map clear" << std::endl;
  m.clear();
  std::cout << "map size is " << m.size() << std::endl;
  std::cout << "map temp size is " << temp.size() << std::endl;
}

int main(int argc, char **argv) {
  std::cout << "hello lch !" << std::endl;

  std::map<int, std::string> m;
  // 插入数据
  m.insert(std::map<int, std::string>::value_type(1, "one"));
  m.insert(std::pair<int, std::string>(2, "two"));
  m.insert(std::make_pair(3, "three"));
  m.insert(std::make_pair<int, std::string>(4, "four"));
  m[5] = "five";
  m.insert({6, "six"});
  m.insert({6, "six"});
  (void)Test1(m);
  (void)Test2(m);
  (void)Test3(m);
  std::cout << "end lch !" << std::endl;
}