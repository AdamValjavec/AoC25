cmake_minimum_required(VERSION 3.10)

project(koordinate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(geslo8 main.cpp povezave.cpp)


add_custom_command(
    TARGET geslo8 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/input.txt
            $<TARGET_FILE_DIR:geslo8>/input.txt
)


