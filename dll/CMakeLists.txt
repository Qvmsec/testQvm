# 设置 CMake 版本要求
cmake_minimum_required(VERSION  3.27.9)
# 定义项目名称
project(MyLibrary)


SET(CMAKE_BUILD_TYPE "Release")
# 将源文件添加到此项目的库
add_library(MyLibrary SHARED 
    main.cpp
)

# 设置输出的库文件名
set_target_properties(MyLibrary PROPERTIES OUTPUT_NAME "MyLibrary")

# 设置生成的库文件的版本信息
set_target_properties(MyLibrary PROPERTIES VERSION 1.0)

# 设置生成的库文件的SOVERSION
set_target_properties(MyLibrary PROPERTIES SOVERSION 1)
