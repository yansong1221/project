cmake_minimum_required(VERSION 2.8)

add_definitions("-Wall -g")
add_definitions(-D BUILD_ENGINE_DLL)

include_directories("/usr/local/include")

aux_source_directory(./ SRC)
ADD_LIBRARY(ServerEngine SHARED ${SRC})