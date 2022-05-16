cmake_minimum_required(VERSION 3.20)
project(Emisia_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(${PROJECT_NAME} src/main.c)

# look for another CMakeLists.txt in directory includes
add_subdirectory(includes)

# allow me to write simply #include "blabla.h" for blabla.h in directory includes in target {P_N}
target_include_directories(${PROJECT_NAME} PRIVATE includes)

# links directory include to the target {P_N}
link_directories(includes)

# links library made in a diferent CMakeLists.txt to target {P_N}
target_link_libraries(${PROJECT_NAME} PRIVATE
        create_ctwl_lib delete_ctwl_lib cur_move_ctwl_lib
        io_ctwl_lib elem_insert_ctwl_lib interpolate_ctwl_lib)