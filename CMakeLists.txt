cmake_minimum_required(VERSION 3.19)
project(labProgrammazione)

set(CMAKE_CXX_STANDARD 14)

add_executable(labProgrammazione main.cpp Note.cpp Note.h Observer.cpp Observer.h Subject.cpp Subject.h User.cpp User.h)