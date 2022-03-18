
# 预处理，生成.i文件
g++ -E demo.cc -o demo.i
# 预处理后的.i文件转换成汇编语言，生成.s文件
g++ -S demo.i -o demo.s
# 将汇编代码转换成目标代码（机器代码），生成.o文件
g++ -c demo.s -o demo.o
# 链接目标代码，生成可执行程序
g++ demo.o -o demo

# 一步执行
# g++ demo.cc demo.o -o demo


### g++参数
# -g 生成调试信息 -Wall 产生所有警告信息 -Werror 所有警告信息当成错误处理
# -I 头文件搜索路径 -L 库路径  -l 具体库

### gcc编译优化
# -O0 不做任何优化，默认编译选项
# -O1 优化占用内存大的大函数，减小代码尺寸，优化编译时间
# -O2 寄存器和指令级的优化，在O1基础上提升代码的执行效率
# -O3 在O2基础上优化，例如普通函数的内联、循环优化、寄存器网络等