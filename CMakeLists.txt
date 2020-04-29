cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(./ServerEngine ServerEngine)
add_subdirectory(./DBServer DBServer)
add_subdirectory(./CenterServer CenterServer)
add_subdirectory(./LoginServer LoginServer)
