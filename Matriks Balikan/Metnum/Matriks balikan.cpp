#include <iostream>
#include <vector>


void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}


std::vector<std::vector<double>> createIdentityMatrix(int size) {
    std::vector<std::vector<double>> identity(size, std::vector<double>(size, 0.0));
    for (int i = 0; i < size; ++i) {
        identity[i][i] = 1.0;
    }
    return identity;
}


void swapRows(std::vector<std::vector<double>>& matrix, int row1, int row2) {
    std::swap(matrix[row1], matrix[row2]);
}


void rowOperation(std::vector<std::vector<double>>& matrix, int targetRow, int pivotRow, double factor) {
    int cols = matrix[0].size();
    for (int i = 0; i < cols; ++i) {
        matrix[targetRow][i] -= factor * matrix[pivotRow][i];
    }
}


std::vector<std::vector<double>> inverseMatrix(const std::vector<std::vector<double>>& matrix) {
    int n = matrix.size();
    std::vector<std::vector<double>> tempMatrix(matrix); 
    std::vector<std::vector<double>> identity = createIdentityMatrix(n);

    // Lakukan eliminasi Gauss-Jordan
    for (int i = 0; i < n; ++i) {
        // Cari pivot non-nol
        int pivotRow = i;
        while (pivotRow < n && tempMatrix[pivotRow][i] == 0) {
            ++pivotRow;
        }
        if (pivotRow == n) {
            std::cerr << "Matriks tidak dapat dibalik (singular)!" << std::endl;
            return std::vector<std::vector<double>>(); 
        }
        
        swapRows(tempMatrix, i, pivotRow);
        swapRows(identity, i, pivotRow);

        
        double pivotElement = tempMatrix[i][i];
        for (int j = 0; j < n; ++j) {
            tempMatrix[i][j] /= pivotElement;
            identity[i][j] /= pivotElement;
        }
       
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = tempMatrix[k][i];
                rowOperation(tempMatrix, k, i, factor);
                rowOperation(identity, k, i, factor);
            }
        }
    }
    return identity;
}

int main() {
    int n;
    std::cout << "Masukkan ukuran matriks (n x n): ";
    std::cin >> n;

   
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
    std::cout << "Masukkan elemen matriks " << n << "x" << n << ":" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "\nMatriks Input:" << std::endl;
    printMatrix(matrix);

   
    std::vector<std::vector<double>> inverse = inverseMatrix(matrix);

    if (!inverse.empty()) {
        std::cout << "\nMatriks Balikan:" << std::endl;
        printMatrix(inverse);
    }

    return 0;
}
