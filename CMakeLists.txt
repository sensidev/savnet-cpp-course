cmake_minimum_required(VERSION 3.15)
project(savnet_cpp)

set(CMAKE_CXX_STANDARD 14)

set(APP sandbox)
#set(APP exp-declaration-vs-definition)
#set(APP exp-polymorphism)
#set(APP exp-new-delete)
set(APP exp-tinder)
#set(APP lab-1.7.3.1)
#set(APP lab-2.4.23.1)
#set(APP lab-5.1.9.2)
#set(APP lab-5.1.9.1)
#set(APP lab-4.5.7)

include_directories(${PROJECT_NAME} PUBLIC apps/${APP}/)

file(GLOB_RECURSE APP_HEADER_FILES apps/${APP}/*.h)
file(GLOB_RECURSE APP_SOURCE_FILES apps/${APP}/*.cpp)

add_executable(${APP}
        ${APP_HEADER_FILES}
        ${APP_SOURCE_FILES}
        )

