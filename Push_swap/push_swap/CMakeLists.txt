cmake_minimum_required(VERSION 3.6)
project(push_swap)

set(CMAKE_C_STANDARD 99)

set(MY_LIB C:/Users/Denys/Documents/GitHub/UNIT/Push_swap/lib/libget_nex_line.a)

set(SOURCE_FILES
        bubble_sort.c
        doubly_linked_list.c
        find_sort_algorithm.c
        main.c
        ps_applay_instructions.c
        q_sort_1.c)

add_executable(push_swap ${SOURCE_FILES})
target_link_libraries(push_swap ${MY_LIB})