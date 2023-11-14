cmake_minimum_required(VERSION 3.10)
project(Server)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED)

add_executable(server main.cpp)
target_include_directories(server PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(server PRIVATE ${Boost_LIBRARIES})
