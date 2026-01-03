cmake_minimum_required(VERSION 3.10)

project(baterije3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(geslo3 main.cpp baterije3.cpp)


add_custom_command(
    TARGET geslo3 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/input.txt
            $<TARGET_FILE_DIR:geslo3>/input.txt
)


