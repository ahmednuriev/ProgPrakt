#include <iostream>
#include <cmath>

using namespace std;

// Функция для вычисления значения функции f(x1, x2, x3)
double f(double x1, double x2, double x3) {
    return exp(x1 * x1 + x2 * x2) + log(4 + x2 * x2 + 2 * x3 * x3);
}

// Функция для нахождения оптимума методом покоординатного спуска
void coordinate_descent(double& x1, double& x2, double& x3, double alpha, double epsilon, int max_iter) {
    int iter = 0;
    double prev_x1, prev_x2, prev_x3;
    
    do {
        prev_x1 = x1;
        prev_x2 = x2;
        prev_x3 = x3;
        
        // Обновление x1
        x1 = prev_x1 - alpha * (2 * prev_x1 * exp(prev_x1 * prev_x1 + prev_x2 * prev_x2));
        
        // Обновление x2
        x2 = prev_x2 - alpha * (2 * prev_x2 * exp(prev_x1 * prev_x1 + prev_x2 * prev_x2) + 2 * prev_x2 / (4 + prev_x2 * prev_x2 + 2 * prev_x3 * prev_x3));
        
        // Обновление x3
        x3 = prev_x3 - alpha * (4 * prev_x3 / (4 + prev_x2 * prev_x2 + 2 * prev_x3 * prev_x3));
        
        iter++;
    } while (iter < max_iter && (fabs(x1 - prev_x1) > epsilon || fabs(x2 - prev_x2) > epsilon || fabs(x3 - prev_x3) > epsilon));
}

int main() {
    double x1 = 1.0;  // начальное приближение x1
    double x2 = 1.0;  // начальное приближение x2
    double x3 = 1.0;  // начальное приближение x3
    double alpha = 0.1;  // коэффициент шага
    double epsilon = 1e-6;  // критерий останова
    int max_iter = 1000;  // максимальное число итераций
    
    // Вызов метода покоординатного спуска
    coordinate_descent(x1, x2, x3, alpha, epsilon, max_iter);
    
    // Вывод результатов
    cout << "Минимум функции f найден в точке:" << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    cout << "Значение функции f(x1, x2, x3) в этой точке: " << f(x1, x2, x3) << endl;
    
    return 0;
}
