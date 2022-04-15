if [ ! -d build ];then
  echo "build dir not exit, mkdir build"
  mkdir -p build
fi
cd build
rm -rf ./*

# cmake .. -DCMAKE_BUILD_TYPE=Release Debug
cmake .. -DCMAKE_BUILD_TYPE=Debug && make -j
