#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak matriks
void printMatrix(vector<vector<double>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fungsi untuk melakukan dekomposisi Crout
void croutDecomposition(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();
    // Inisialisasi matriks L dan U
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            U[i][j] = 0;
            if (i == j) L[i][j] = 1;
            else L[i][j] = 0;
        }
    }

    // Proses dekomposisi
    for (int j = 0; j < n; j++) {
        for (int i = j; i < n; i++) {
            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += (L[i][k] * U[k][j]);
            }
            U[i][j] = A[i][j] - sum;
        }
        for (int i = j; i < n; i++) {
            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += (L[j][k] * U[k][i]);
            }
            L[i][j] = (A[i][j] - sum) / U[j][j];
        }
    }
}

int main() {
    int n;
    cout << "Masukkan ukuran matriks: ";
    cin >> n;

    // Matriks masukan
    vector<vector<double>> A(n, vector<double>(n));
    cout << "Masukkan elemen matriks A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    // Matriks untuk menyimpan L dan U
    vector<vector<double>> L(n, vector<double>(n)), U(n, vector<double>(n));

    // Melakukan dekomposisi Crout
    croutDecomposition(A, L, U);

    cout << "Matriks L:" << endl;
    printMatrix(L);

    cout << "Matriks U:" << endl;
    printMatrix(U);

    return 0;
}
