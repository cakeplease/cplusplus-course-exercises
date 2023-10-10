cmake_minimum_required(VERSION 3.24)
project(oving3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")
#add_executable(oppgave1 oppgave1.cpp) Denne skal ikke kjøres, den forventer en main() metode. Brukes i andre oppgaver.
add_executable(oppgave2 oppgave2.cpp)
add_executable(oppgave3 oppgave3_test_klient.cpp)
add_executable(oppgave4 oppgave4.cpp)
