# top-level CMakeLists

cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(parallel_eigen LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)


# Source files
add_subdirectory(src)
