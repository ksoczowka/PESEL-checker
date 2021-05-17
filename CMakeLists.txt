cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(PESEL)

set(SRC_LIST
 src/PESEL.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp)
add_library(lib STATIC ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} lib)