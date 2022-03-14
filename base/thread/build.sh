# ./build.sh demo.cc

g++ -std=c++11 -pthread thread_demo.cc -o  thread_demo
g++ -std=c++11 -pthread condition_variable.cc -o  condition_variable