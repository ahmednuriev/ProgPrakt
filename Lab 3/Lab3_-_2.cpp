#include <iostream>
#include <cmath>

double f(double x) {
    return exp(-2 * x) * sin(15 * x);
}

double rectangleMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }
    return sum * h;
}

double trapezoidalMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }
    return sum * h;
}

double simpsonsMethod(double a, double b, int n) {
    if (n % 2 != 0) n++; // n must be even
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += (i % 2 == 0) ? 2 * f(x) : 4 * f(x);
    }
    return sum * h / 3.0;
}

int main() {
    double a = 0.0;
    double b = 10.0; // Use a large number to approximate infinity
    int n = 100000; // Number of subintervals

    std::cout << "Integral of e^(-2x) * sin(15x) from " << a << " to " << b << std::endl;
    std::cout << "Rectangle Method: " << rectangleMethod(a, b, n) << std::endl;
    std::cout << "Trapezoidal Method: " << trapezoidalMethod(a, b, n) << std::endl;
    std::cout << "Simpson's Method: " << simpsonsMethod(a, b, n) << std::endl;

    return 0;
}
