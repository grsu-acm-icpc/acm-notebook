cmake_minimum_required(VERSION 3.5)
project(acm_notebook)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES number\ theory/extended-euclid.cpp)
add_executable(acm_notebook ${SOURCE_FILES})