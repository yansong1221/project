cmake_minimum_required(VERSION 2.8)

add_definitions("-Wall -g")

include_directories("../")

add_subdirectory(../ServerEngine ServerEngine)

aux_source_directory(./ SRC)
add_executable(DBServer ${SRC})
target_link_libraries(DBServer ServerEngine curl uv)


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)