# src-level CMakeLists

add_executable(parallel_eigen
        parallel_eigen.cpp)


# Include the eigen3 headers
target_include_directories(parallel_eigen PUBLIC /opt/local/include/eigen3)

