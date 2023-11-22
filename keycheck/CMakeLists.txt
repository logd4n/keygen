cmake_minimum_required(VERSION 3.2)

project(keycheck)

find_library(KEYCHECK keycheck.a ./)

file(GLOB
CPPS "*.cpp")

add_executable(${PROJECT_NAME} ${CPPS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${KEYCHECK})
