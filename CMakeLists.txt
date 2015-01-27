cmake_minimum_required(VERSION 2.8.4)
project(boost_session01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)

include_directories(/usr/local/include/boost)

add_executable(boost_session01 ${SOURCE_FILES})