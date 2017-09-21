#include <Eigen/Dense>
#include <iostream>

#include <ctime>


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

    std::vector<unsigned> dims = {100, 250, 500};

    // Random matrices
    // random_diag(dims);

    // Symmetric random matrices
    symm_diag(dims);

    // Parallel random matrices
    parallel_random_diag(dims, 2);
    parallel_random_diag(dims, 2);
}
