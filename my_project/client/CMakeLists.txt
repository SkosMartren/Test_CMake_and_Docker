cmake_minimum_required(VERSION 3.10)
project(Client)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED)

add_executable(client main.cpp)
target_include_directories(client PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(client PRIVATE ${Boost_LIBRARIES})
