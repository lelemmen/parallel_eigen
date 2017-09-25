# src-level CMakeLists

# Source files
add_executable(parallel_eigen
        parallel_eigen.cpp)

# Include the Eigen3 headers
target_include_directories(parallel_eigen PRIVATE /opt/local/include/eigen3)


# Use the -O1 compiler flag
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")

# Use the -O2 compiler flag
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

# Use Intel MKL
target_include_directories(parallel_eigen PRIVATE $ENV{MKL_ROOT}/include)
# https://software.intel.com/en-us/articles/intel-mkl-link-line-advisor/
target_link_libraries(parallel_eigen mkl_intel_ilp64 mkl_intel_thread mkl_core iomp5 pthread m dl)
