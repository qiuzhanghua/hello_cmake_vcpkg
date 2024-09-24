cmake_minimum_required(VERSION 3.30)

project(Hello)

find_package(fmt CONFIG REQUIRED)

add_executable(Hello main.cpp)

target_link_libraries(Hello PRIVATE fmt::fmt)
