cmake_minimum_required(VERSION 3.14)
project(suggestLib)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp suggestLib.cpp)

add_library(suggestLib ${SOURCE_FILES})