#include <iostream>
#include <vector>
#include <string>

/*
参考：https://www.cnblogs.com/lijingran/p/8619711.html
应用：字符串匹配，在源字符串ptr中查找目标字符串str在ptr中开始出现的下标值
普通方法：两种for循环遍历，时间复杂度为O(m * n)
KMP算法：时间复杂度为O(m + n)，
*/

void cal_next(const char *str, int *next, int len)
{
    next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    int k = -1;//k初始化为-1
    for (int q = 1; q <= len-1; q++)
    {
        while (k > -1 && str[k + 1] != str[q])//如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
        {
            k = next[k];//往前回溯
        }
        if (str[k + 1] == str[q])//如果相同，k++
        {
            k = k + 1;
        }
        next[q] = k;//这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
    }
}

int KMP(const char *str, int slen, const char *ptr, int plen)
{
    int *next = new int[plen];
    cal_next(ptr, next, plen);//计算next数组
    int k = -1;
    for (int i = 0; i < slen; i++)
    {
        while (k >-1&& ptr[k + 1] != str[i])//ptr和str不匹配，且k>-1（表示ptr和str有部分匹配）
            k = next[k];//往前回溯
        if (ptr[k + 1] == str[i])
            k = k + 1;
        if (k == plen-1)//说明k移动到ptr的最末端
        {
            //cout << "在位置" << i-plen+1<< endl;
            //k = -1;//重新初始化，寻找下一个
            //i = i - plen + 1;//i定位到该位置，外层for循环i++可以继续找下一个（这里默认存在两个匹配字符串可以部分重叠），感谢评论中同学指出错误。
            return i-plen+1;//返回相应的位置
        }
    }
    return -1;  
}

void Test1() {
  std::cout << "------------------------------start Test1------------------------------" << std::endl;
  const char *str = "bacbababadababacambabacaddababacasdsd";
  const char *ptr = "ababaca";
  int a = KMP(str, 36, ptr, 7);
  std::cout << a << std::endl;
  std::cout << "------------------------------end Test1------------------------------" << std::endl;
}

void Test2() {
    std::cout << "------------------------------start Test2------------------------------" << std::endl;
    
    std::string str = "Hello";
    std::vector<std::string> v;
    //调用常规的拷贝构造函数，新建字符数组，拷贝数据
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";
    //调用移动构造函数，掏空str，掏空后，最好不要使用str
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";
    std::cout << "The contents of the vector are \"" << v[0]
                                         << "\", \"" << v[1] << "\"\n";
    std::cout << "------------------------------end Test2------------------------------" << std::endl;
}

int main(int argc, char **argv) {
  std::cout << "hello lch !" << std::endl;
  (void)Test1();
  (void)Test2();
  std::cout << "end lch !" << std::endl;
}
