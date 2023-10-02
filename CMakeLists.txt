# cmake 最低版本要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project(fake_cache)

add_executable(test Status.h Device.h Device.cpp Memory.h Memory.cpp Cache.h Cache.cpp Controll.h Controll.cpp test.cpp)

include_directories("/usr/local/include")