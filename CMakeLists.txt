cmake_minimum_required(VERSION 3.10)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)

find_package(fmt REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(Algorithms ${SOURCES})

target_link_libraries(Algorithms fmt::fmt)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
