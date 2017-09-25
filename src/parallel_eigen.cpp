#include <iostream>
#include <chrono>

#include <Eigen/Dense>


/** Check whether a given matrix is symmetric
 */
bool is_symmetric(Eigen::MatrixXd& A) {
    return A.isApprox(A.transpose(), 1.0e-8);
}

/** Return a random symmetric matrix
 */
Eigen::MatrixXd random_symmetric_matrix(size_t dim) {
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(dim, dim);
    Eigen::MatrixXd AT = A.transpose();
    Eigen::MatrixXd S = A + AT;     // The sum of a matrix and its transpose is symmetric

    assert(is_symmetric(S));        // Double-check that S is symmetric
    return S;
}




void time_diagonalization(std::vector<size_t> dims) {
    for(const auto& dim : dims) {
        // Prepare the random symmetric matrix
        Eigen::MatrixXd A = random_symmetric_matrix(dim);

        // Time the diagonalization
        auto start = std::chrono::high_resolution_clock::now();
        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> saes (A);
        auto stop = std::chrono::high_resolution_clock::now();

        // Process the chrono time and output
        auto elapsed_time = stop - start;           // in nanoseconds
        auto seconds = elapsed_time.count() / 1e9;  // in seconds
        std::cout << dim << " : " << seconds << std::endl;
    }
}



int main () {

    std::vector<size_t> dims {50, 100, 250, 500, 1000, 2500, 5000, 10000};

    time_diagonalization(dims);


    return 0;
}
