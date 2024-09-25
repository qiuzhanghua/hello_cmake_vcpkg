cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED ON)

project(Hello)

find_package(fmt CONFIG REQUIRED)

add_executable(hello main.cpp)

# include(FetchContent)
# FetchContent_Declare(
#   spdlog
#   GIT_REPOSITORY https://github.com/gabime/spdlog.git
#   GIT_TAG v1.14.1
# )
# FetchContent_MakeAvailable(spdlog)

find_package(spdlog CONFIG REQUIRED)

target_link_libraries(hello PRIVATE fmt::fmt spdlog::spdlog)

