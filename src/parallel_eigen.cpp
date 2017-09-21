#include <Eigen/Dense>
#include <iostream>
#include <ctime>


void random_mult(std::vector<unsigned>& dims) {
    std::cout << "Multiplying random matrices" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Number of cores that eigen will use: " << Eigen::nbThreads() << std::endl  << std::endl;

    for (const auto& dim : dims) {
        const clock_t begin_time = clock();

        Eigen::MatrixXd A = Eigen::MatrixXd::Random(dim, dim);
        Eigen::MatrixXd B = Eigen::MatrixXd::Random(dim, dim);
        A * B;

        std::cout << "dim: "  << dim << "\t multiplication time: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << " seconds" << std::endl;
    }


}


void random_diag(std::vector<unsigned>& dims) {
    std::cout << "Diagonalizing random matrices" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Number of cores that eigen will use: " << Eigen::nbThreads() << std::endl  << std::endl;

    for (const auto& dim : dims) {
        const clock_t begin_time = clock();

        Eigen::MatrixXd A = Eigen::MatrixXd::Random(dim, dim);
        Eigen::EigenSolver<Eigen::MatrixXd> es (A);

        std::cout << "dim: "  << dim << "\t diagonalization time: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << " seconds" << std::endl;
    }
}


void symm_diag(std::vector<unsigned>& dims) {
    std::cout << "Diagonalizing symmetric matrices" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Number of cores that eigen will use: " << Eigen::nbThreads() << std::endl << std::endl;

    for (const auto& dim : dims) {
        const clock_t begin_time = clock();

        Eigen::MatrixXd A = Eigen::MatrixXd::Random(dim, dim);
        Eigen::MatrixXd AT = A.transpose();
        Eigen::MatrixXd S = A + AT;

        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> saes (S);
        std::cout << "dim: "  << dim << "\t diagonalization time: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << " seconds" << std::endl;
    }
}


void parallel_random_diag(std::vector<unsigned>& dims, unsigned cores) {
    Eigen::setNbThreads(cores);
    std::cout << "Diagonalizing random matrices" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Number of cores that eigen will use: " << Eigen::nbThreads() << std::endl  << std::endl;

    for (const auto& dim : dims) {
        const clock_t begin_time = clock();

        Eigen::MatrixXd A = Eigen::MatrixXd::Random(dim, dim);
        Eigen::EigenSolver<Eigen::MatrixXd> es (A);

        std::cout << "dim: "  << dim << "\t diagonalization time: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << " seconds" << std::endl;
    }

}


int main () {

#if defined(_OPENMP)
    std::cout << "Number of processors available: " << omp_get_num_procs() << std::endl;
    std::cout << "Maximum number of threads: " << omp_get_max_threads() << std::endl;
#endif

    using namespace Eigen;
    int n = 40000;

    MatrixXd D = MatrixXd::Random(n,n);

    EigenSolver<MatrixXd> es (D);
}
