cmake_minimum_required(VERSION 3.15.0)
project(cppast_one_file VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    cppast

    GIT_REPOSITORY https://github.com/standardese/cppast.git
    GIT_TAG origin/main
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(cppast)

add_executable(cppast_one_file main.cpp)
target_link_libraries(cppast_one_file PUBLIC cppast)
target_compile_definitions(cppast_one_file PUBLIC PARSE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/example.h")


