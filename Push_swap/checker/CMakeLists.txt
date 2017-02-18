cmake_minimum_required(VERSION 3.6)
project(checker)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c checker.h check_instructions.c)
add_executable(checker ${SOURCE_FILES})