cmake_minimum_required(VERSION 3.15)
project(savnet_cpp)

set(CMAKE_CXX_STANDARD 14)

set(APP sandbox)
#set(APP lab-1.7.3.1)
#set(APP lab-2.4.23.1)

include_directories(${PROJECT_NAME} PUBLIC apps/${APP}/)

add_executable(${APP} apps/${APP}/main.cpp)

