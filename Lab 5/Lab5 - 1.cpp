#include <iostream>
#include <cmath>
using namespace std;


struct Node {
    double x;
    double y;
};

void cubicSpline(Node nodes[], int n, double x_interp) {
    // Вычисление коэффициентов для кубического сплайна
    double h[n], alpha[n], l[n+1], mu[n+1], z[n+1], c[n+1], b[n+1], d[n+1];

    // Вычисление h_i
    for (int i = 0; i < n; ++i) {
        h[i] = nodes[i+1].x - nodes[i].x;
    }

    // Вычисление alpha_i
    for (int i = 1; i < n; ++i) {
        alpha[i] = 3.0 * (nodes[i+1].y - nodes[i].y) / h[i] - 3.0 * (nodes[i].y - nodes[i-1].y) / h[i-1];
    }

    // Решение системы уравнений методом прогонки
    l[0] = 1.0;
    mu[0] = 0.0;
    z[0] = 0.0;

    for (int i = 1; i < n; ++i) {
        l[i] = 2.0 * (nodes[i+1].x - nodes[i-1].x) - h[i-1] * mu[i-1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i-1] * z[i-1]) / l[i];
    }

    l[n] = 1.0;
    z[n] = 0.0;
    c[n] = 0.0;

    // Вычисление коэффициентов сплайна
    for (int j = n - 1; j >= 0; --j) {
        c[j] = z[j] - mu[j] * c[j+1];
        b[j] = (nodes[j+1].y - nodes[j].y) / h[j] - h[j] * (c[j+1] + 2.0 * c[j]) / 3.0;
        d[j] = (c[j+1] - c[j]) / (3.0 * h[j]);
    }

    // Оценка значения сплайна в точке x_interp
    int interval = 0;
    for (int i = 0; i < n; ++i) {
        if (x_interp >= nodes[i].x && x_interp <= nodes[i+1].x) {
            interval = i;
            break;
        }
    }

    double dx = x_interp - nodes[interval].x;
    double interpolated_value = nodes[interval].y + b[interval] * dx + c[interval] * pow(dx, 2) + d[interval] * pow(dx, 3);

    // Вывод результата
    cout << "Значение сплайна в точке x = " << x_interp << ": " << interpolated_value << endl;
}

int main() {
    // Инициализация узлов интерполяции
    Node nodes[] = {
        {0.0, 0.0},
        {1.0, 0.5},
        {2.0, 0.86603},
        {3.0, 1.0},
        {4.0, 0.86603}
    };
    int n = sizeof(nodes) / sizeof(nodes[0]) - 1; // количество интервалов

    double x_interp = 1.5;

    // Вызов функции для вычисления кубического сплайна и значения в точке x_interp
    cubicSpline(nodes, n, x_interp);

    return 0;
}

