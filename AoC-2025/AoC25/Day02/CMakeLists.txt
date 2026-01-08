cmake_minimum_required(VERSION 3.10)

project(baterije)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(geslo2 main.cpp baterije.cpp)


add_custom_command(
    TARGET geslo2 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/input.txt
            $<TARGET_FILE_DIR:geslo2>/input.txt
)


