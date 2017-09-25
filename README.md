# parallel_eigen

Benchmark code and results for parallelizing the diagonalization of matrices using Eigen3.


## Dependencies
[![eigen3 Dependency](https://img.shields.io/badge/eigen-3+-blue.svg)](http://eigen.tuxfamily.org/index.php?title=Main_Page)


## Goal

The goal of this project is to find out some timings of full diagonalizations of large, symmetric matrices using the Eigen3 library.


## Timings

### Preliminary testings
With standard Eigen3, we get the following timings (in seconds):

    50 : 0.01052
    100 : 0.069083
    250 : 0.731172
    500 : 4.90927
    1000 : 36.3127
    2500 : 547.119