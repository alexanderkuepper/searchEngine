cmake_minimum_required(VERSION 3.26)
project(searchEngine)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(DateConverter_run ${SOURCE_FILES})

include_directories(src)
add_subdirectory(src)

target_link_libraries(DateConverter_run src)

add_subdirectory(test)