#include <iostream>
#include <vector>

using namespace std;

// Метод прогонки для решения системы линейных уравнений
vector<double> tridiagonalMethod(vector<double> a, vector<double> b, vector<double> c, vector<double> d) {
    int n = a.size();
    vector<double> p(n), q(n), x(n);

    // Прямой ход
    p[0] = -b[0] / a[0];
    q[0] = d[0] / a[0];

    for (int i = 1; i < n; ++i) {
        double denominator = a[i] + c[i - 1] * p[i - 1];
        p[i] = -b[i] / denominator;
        q[i] = (d[i] - c[i - 1] * q[i - 1]) / denominator;
    }

    // Обратный ход
    x[n - 1] = q[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        x[i] = p[i] * x[i + 1] + q[i];
    }

    return x;
}

int main() {
    // Коэффициенты системы
    vector<double> a = {-11, 17, 20, -20, 8};
    vector<double> b = {9, 6, 8, 4, 0};
    vector<double> c = {0, 9, 5, -6, 2};
    vector<double> d = {-117, -97, -6, 59, -86};

    // Решение системы методом прогонки
    vector<double> solution = tridiagonalMethod(a, b, c, d);

    // Вывод решения
    cout << "Решение системы:" << endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        cout << "x" << (i + 1) << " = " << solution[i] << endl;
    }

    return 0;
}
