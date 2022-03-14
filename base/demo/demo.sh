
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
