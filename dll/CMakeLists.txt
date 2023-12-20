cmake_minimum_required (VERSION 3.7)
PROJECT(MyLibrary CXX)
# 将源代码添加到此项目的可执行文件。
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/dll/ ${CMAKE_CURRENT_SOURCE_DIR})

add_executable (MyLibrary "main.cpp" ${RES_PATH})
# TARGET_LINK_LIBRARIES(MyLibrary hello)
