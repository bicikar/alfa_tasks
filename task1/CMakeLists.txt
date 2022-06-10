cmake_minimum_required(VERSION 3.20)
project(brackets C)

set(CMAKE_C_STANDARD 99)

add_executable(brackets main.c brackets.c brackets.h)
