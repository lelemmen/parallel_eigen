# parallel_eigen

Benchmark code and results for parallelizing the diagonalization of matrices using Eigen3.


## Dependencies
[![eigen3 Dependency](https://img.shields.io/badge/eigen-3+-blue.svg)](http://eigen.tuxfamily.org/index.php?title=Main_Page)


## Goal

The goal of this project is to find out some timings of full diagonalizations of large, symmetric matrices using the Eigen3 library, on my machine. Specifications:
 * MacBook Pro, mid 2015
 * Processor: 2,5 GHz Intel Core i7 (8 hyper-threaded cores, 256KB L2, 6 MB L3)
 * 16 GB 1600 MHz DDR3
 * Intel Iris Pro 1536 MB VRAM

C++ Compiler:
 * (MacPorts gcc49 4.9.4_2) 4.9.4


## Timings

### Preliminary testings
With standard Eigen3, we get the following timings (in seconds):

    50 : 0.01052
    100 : 0.069083
    250 : 0.731172
    500 : 4.90927
    1000 : 36.3127
    2500 : 547.119


### -01 compiler flag
Using the `-01` compiler flag, we expect faster results:

    50 : 0.000365
    100 : 0.00218
    250 : 0.031781
    500 : 0.216862
    1000 : 1.63663
    2500 : 28.3627
    5000 : 261.308


### -O2 compiler flag
Using the `-O2` compiler flag, we expect even faster results, but the differences seem to be negligible, and it seems that for large matrices, `-O1` is preferable:

    50 : 0.000383
    100 : 0.002076
    250 : 0.029242
    500 : 0.249875
    1000 : 1.85681
    2500 : 28.2351
    5000 : 270.23

### EIGEN_USE_MKL_ALL
Using the `#define EIGEN_USE_MKL_ALL` macro, we expect Eigen3 to be able to do everything in parallel. Here are the timings (without any optimization flags):

    50 : 0.057216
    100 : 0.005237
    250 : 0.010387
    500 : 0.039365
    1000 : 0.181756
    2500 : 2.14403
    5000 : 18.4512
    10000 : 149.752

