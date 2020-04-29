cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 17)
#add_definitions("-Wall -g")

include_directories("../")

#add_subdirectory(../ServerEngine ServerEngine)

aux_source_directory(./ SRC)
add_executable(LoginServer ${SRC})
target_link_libraries(LoginServer ServerEngine curl-d uv mysqlclient)


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)