# src-level CMakeLists

# Source files
add_executable(parallel_eigen
        parallel_eigen.cpp)

# Include the Eigen3 headers
target_include_directories(parallel_eigen PUBLIC /opt/local/include/eigen3)