cmake_minimum_required(VERSION 3.5)
project(templatesProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CFile.h CElement.h CElement.cpp)
add_executable(templatesProject ${SOURCE_FILES})