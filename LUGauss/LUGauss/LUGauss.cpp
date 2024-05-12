#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk melakukan dekomposisi LU Gauss
void gaussianLUDecomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();
    L = vector<vector<double>>(n, vector<double>(n, 0.0));
    U = vector<vector<double>>(n, vector<double>(n, 0.0));

    // Inisialisasi matriks identitas untuk L
    for (int i = 0; i < n; i++) {
        L[i][i] = 1.0;
    }

    for (int j = 0; j < n; j++) {
        // Bagian atas dari U
        for (int i = 0; i <= j; i++) {
            double sum = 0.0;
            for (int k = 0; k < i; k++) {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;
        }

        // Bagian bawah dari L
        for (int i = j + 1; i < n; i++) {
            double sum = 0.0;
            for (int k = 0; k < j; k++) {
                sum += L[i][k] * U[k][j];
            }
            L[i][j] = (A[i][j] - sum) / U[j][j];
        }
    }
}

int main() {
    int n;
    cout << "Masukkan ukuran matriks (n x n): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    cout << "Masukkan elemen-elemen matriks:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    vector<vector<double>> L, U;
    gaussianLUDecomposition(A, L, U);

    // Menampilkan hasil dekomposisi LU Gauss
    cout << "Matriks L:" << endl;
    for (const auto& row : L) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "Matriks U:" << endl;
    for (const auto& row : U) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}