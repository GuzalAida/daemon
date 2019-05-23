cmake_minimum_required(VERSION 3.1)
project(guzald)

set(CMAKE_BUILD_TYPE "Release") 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

include_directories(./)
add_executable(${PROJECT_NAME} "guzald.c")
target_link_libraries(${PROJECT_NAME} PRIVATE)
