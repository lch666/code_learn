#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

void Test1() {
  std::cout << "------------------------------start Test1------------------------------" << std::endl;
  const char *s = "hello world";
  static const char *st = "hello world";
  const char st1[] = "hello lch";
  std::string s1 = "hello world";
  std::string s2("hello world");
  std::string s3(10, 'c');
  std::string s4(s);
  std::string s5(st);
  std::string s6(s3);
  std::string s7(st1);
  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
  std::cout << s3 << std::endl;
  std::cout << s4 << std::endl;
  std::cout << s5 << std::endl;
  std::cout << s6 << std::endl;
  std::cout << s7 << std::endl;
  std::cout << "------------------------------end Test1------------------------------" << std::endl;
}

void Test2() {
  std::cout << "------------------------------start Test2------------------------------" << std::endl;
  std::string s = "0123456789";
  std::string s1 = "0123456789";
  std::cout << "s.at(5) is" << s.at(5) << std::endl;
  std::cout << "s[5] is" << s[5] << std::endl;
  std::cout << "s size is " << s.size() << std::endl;
  std::cout << "s max size is " << s.max_size() << std::endl;
  std::cout << "s length is " << s.length() << std::endl;
  std::cout << "s1 empty is " << s1.empty() << std::endl;
  std::cout << "s1 clear " << std::endl; s1.clear();
  std::cout << "s1 empty is " << s1.empty() << std::endl;
  std::cout << "s s1 swap " << std::endl; s.swap(s1);
  std::cout << "s size is " << s.size() << std::endl;
  std::cout << "s1 size is " << s1.size() << std::endl;
  std::cout << "------------------------------end Test2------------------------------" << std::endl;
}

void Test3() {
  std::cout << "------------------------------start Test3------------------------------" << std::endl;
  std::string s = "123456789";
  std::string s1 = "abc";
  std::cout << "string s is " << s << std::endl; 
  std::cout << "string s1 is " << s1 << std::endl; 
  s.insert(8, s1);
  std::cout << "s.insert(8, s1) is " << s << std::endl;  // 在第8个位置插入新的字符串
  s.insert(6, s1, 1);
  std::cout << "s.insert(6, s1, 1) is " << s << std::endl; 
  s.insert(4, s1, 0, 2);
  std::cout << "s.inserts.insert(6, s1, 0, 2) is " << s << std::endl; 
  std::cout << "s.find abc " << s.find("abc") << std::endl;  // 返回第一次出现的位置
  std::cout << "s.find abcde " << (s.find("abcde") != std::string::npos) << std::endl;  // 没有找到返回std::string::npos
  std::cout << "s find a " << s.find('a') << std::endl;
  std::cout << "s find a after index 5 " << s.find('a', 5) << std::endl;
  std::cout << "s append abcd " << s.append("abcd") << std::endl;
  std::cout << "s append aaa " << s.append(3, 'a') << std::endl;
  std::cout << "s append bbb " << s.append("bbbbbbb", 3) << std::endl;
  std::cout << "s after 3 index substr 10 char is " << s.substr(3, 10) << std::endl;  // 从第三个位置开始截取10个字符
  char *s2 = new char[3];
  s.copy(s2, 3, 1);
  std::cout << "s copy 3 char after index 1 is " << s2 << std::endl;
  // auto begin = s.begin();  // 返回begin迭代器
  const char *temp = new char[40];
  temp = s.c_str();
  std::cout << "sting s c_str is " << temp << std::endl;
  std::cout << "sting s c_str is " << s.c_str() << std::endl;
  std::cout << "string s data is " << s.data() << std::endl;  // 以字符数组的形式返回
  std::cout << "------------------------------end Test3------------------------------" << std::endl;
}

void Test4() {
  std::cout << "------------------------------start Test4------------------------------" << std::endl;
  std::string s = "123456789";
  std::cout << "string s is " << s << std::endl;
  s+="abc";
  std::cout << "string s + abc is " << s << std::endl;
  s.push_back('a');
  std::cout << "string s push_back a is " << s << std::endl;
  std::cout << "string s capacity is " << s.capacity() << std::endl;
  std::cout << "string s size is " << s.size() << std::endl;
  s.assign("12345");
  std::cout << "string s assign 12345 is " << s << std::endl;
  std::cout << "string s capacity is " << s.capacity() << std::endl;
  std::cout << "string s size is " << s.size() << std::endl;
  s.replace(1, 2, "abcdef");  // 将下标1开始的两个字符替换为abcdef
  std::cout << "string s replace abcdef is " << s << std::endl;
  s.erase(8);
  std::cout << "string erase after index 8 is " << s << std::endl;
  s.erase(3, 2);
  std::cout << "string erase after index 3, erase 2 char is " << s << std::endl;
  s+="abcabc";
  std::cout << "string s += abcabc is " << s << std::endl;
  std::cout << "string s find first of a is " << s.find_first_of('a') << std::endl;
  std::cout << "string s find last of a is " << s.find_last_of('a') << std::endl;
  std::cout << "string s find first not of a is " << s.find_first_not_of('a') << std::endl;
  std::cout << "string s find last of not a is " << s.find_last_not_of('a') << std::endl;
  std::cout << "------------------------------end Test4------------------------------" << std::endl;
}

void Test5() {
  std::cout << "------------------------------start Test5------------------------------" << std::endl;
  std::string s = "hello world, this is lch !!!";
  std::istringstream is(s);
  std::string s1, s2, s3, s4, s5, s6;
  is >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
  std::ostringstream os;
  os << s1 << s2 << s3 << s4 << s5 << s6;
  std::cout << os.str() << std::endl;
  std::cout << "------------------------------end Test5------------------------------" << std::endl;
}

void Test6() {
  std::cout << "------------------------------start Test6------------------------------" << std::endl;
  std::string s = "我是谁";
  std::cout << "string s is " << s << "  string 我是谁 size is " << s.size() << std::endl;
  std::sort(s.begin(), s.end());
  std::cout << "string s is " << s << "  string 我是谁 size is " << s.size() << std::endl;
  std::string s1 = "987654321";
  std::cout << "string s1 is " << s1 << std::endl;
  std::sort(s1.begin(), s1.end());
  std::cout << "after sort, string s1 is " << s1 << std::endl;
  for (auto iter = s1.begin(); iter != s1.end(); iter++) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;
  std::cout << "------------------------------end Test6------------------------------" << std::endl;
}

int main(int argc, char **argv) {
  std::cout << "hello lch !" << std::endl;
  (void)Test1();  // 字符串赋值
  (void)Test2();  // 常用函数
  (void)Test3();  // 常用操作
  (void)Test4();  // 常用操作
  (void)Test5();  // 字符串流处理
  (void)Test6();
  std::cout << "end lch !" << std::endl;
}



