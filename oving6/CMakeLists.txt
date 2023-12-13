cmake_minimum_required(VERSION 3.24)
project(oving6)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")
#[[find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})]]

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra") in case we still need -pthread for threading


add_executable(oppgave1 oppgave1.cpp)
add_executable(oppgave2 oppgave2.cpp)
#[[
target_link_libraries(oppgave2 ${Boost_LIBRARIES})]]
