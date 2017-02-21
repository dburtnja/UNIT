cmake_minimum_required(VERSION 3.6)
project(checker)

set(CMAKE_C_STANDARD 99)

set(MY_LIB C:/Users/Denys/Documents/GitHub/UNIT/Push_swap/lib/libget_nex_line.a)
set(SOURCE_FILES main.c check_instructions.c
        applay_instructions.c doubly_linked_list.c)
add_executable(checker ${SOURCE_FILES})
target_link_libraries(checker ${MY_LIB})