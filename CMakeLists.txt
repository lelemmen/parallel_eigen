# top-level CMakeLists

cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)

project(parallel_eigen LANGUAGES CXX)


# C++ compiler
message(WARNING "Using C++ compiler: " ${CMAKE_CXX_COMPILER})



# Enable parallellized code with OMP
find_package(openmp)
if (OPENMP_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")   # set the C++ compiler flags
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()


# Source files
add_executable(parallel_eigen
        src/parallel_eigen.cpp)


add_executable(test_parallel
        src/test_parallel.cpp)


# Include the eigen3 headers
target_include_directories(parallel_eigen PUBLIC /opt/local/include/eigen3)