cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

add_definitions("-Wall -g")

include_directories("./ServerEngine")
add_subdirectory(./ServerEngine ServerEngine)
link_directories(ServerEngine "/usr/local/lib")

add_executable(main main.cpp)
target_link_libraries(main ServerEngine uv)
