cmake_minimum_required(VERSION 3.15)
project(leetcode_cpp LANGUAGES CXX)

# C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 警告 & MSVC UTF-8
if (MSVC)
    add_compile_options(/W4 /utf-8)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 头文件目录（可留空）
include_directories(${CMAKE_SOURCE_DIR}/include)

# 自动把 src 下每个 .cpp 变成一个独立可执行文件
file(GLOB CONFIGURE_DEPENDS PROBLEM_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
foreach(source ${PROBLEM_SOURCES})
    get_filename_component(fname ${source} NAME_WE) # 不带扩展名
    add_executable(${fname} ${source}
            src/0001.cpp)
endforeach()