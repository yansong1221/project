cmake_minimum_required(VERSION 2.8)

add_definitions("-Wall -g")

include_directories("/usr/local/include")
aux_source_directory(./ SRC)
ADD_LIBRARY(ServerEngine STATIC ${SRC})