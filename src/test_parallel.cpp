#include <omp.h>
#include <iostream>

int main () {

#if defined(_OPENMP)

#pragma omp parallel
    {
    std::cout << "Hello World from thread number " << omp_get_thread_num() << std::endl;
    }
#endif


}