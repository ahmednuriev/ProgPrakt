#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Вычисление определителя 3x3
double determinant3x3(vector<vector<double>> mat) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
         - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
         + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

// Метод Крамера
vector<double> cramerMethod(vector<vector<double>> A, vector<double> b) {
    double detA = determinant3x3(A);

    if (detA == 0) {
        throw runtime_error("Система не имеет единственного решения.");
    }

    vector<vector<double>> A1 = A, A2 = A, A3 = A;
    for (int i = 0; i < 3; ++i) {
        A1[i][0] = b[i];
        A2[i][1] = b[i];
        A3[i][2] = b[i];
    }

    double detA1 = determinant3x3(A1);
    double detA2 = determinant3x3(A2);
    double detA3 = determinant3x3(A3);

    return {detA1 / detA, detA2 / detA, detA3 / detA};
}

// Метод Якоби
vector<double> jacobiMethod(vector<vector<double>> A, vector<double> b, int maxIterations = 100, double tolerance = 1e-10) {
    vector<double> x(3, 0.0); // Начальное приближение

    for (int iter = 0; iter < maxIterations; ++iter) {
        vector<double> x_new(3, 0.0);

        for (int i = 0; i < 3; ++i) {
            double sigma = 0.0;
            for (int j = 0; j < 3; ++j) {
                if (i != j) {
                    sigma += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sigma) / A[i][i];
        }

        double error = 0.0;
        for (int i = 0; i < 3; ++i) {
            error += abs(x_new[i] - x[i]);
        }

        if (error < tolerance) {
            return x_new;
        }

        x = x_new;
    }

    throw runtime_error("Метод Якоби не сошелся.");
}

int main() {
    vector<vector<double>> A = {
        {5, -2, 1},
        {2, -1, 1},
        {18, -8, 4}
    };

    vector<double> b = {2, -1, 0};

    // Решение методом Крамера
    try {
        vector<double> resultCramer = cramerMethod(A, b);
        cout << "Метод Крамера: x1 = " << resultCramer[0] << ", x2 = " << resultCramer[1] << ", x3 = " << resultCramer[2] << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    // Решение методом Якоби
    try {
        vector<double> resultJacobi = jacobiMethod(A, b);
        cout << "Метод Якоби: x1 = " << resultJacobi[0] << ", x2 = " << resultJacobi[1] << ", x3 = " << resultJacobi[2] << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
