#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Vector {
    double x;
    double y;
};

double vectorLength(const Vector& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

double dotProduct(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y;
}

double angleBetween(const Vector& a, const Vector& b) {
    double dot = dotProduct(a, b);
    double lenA = vectorLength(a);
    double lenB = vectorLength(b);
    return acos(dot / (lenA * lenB)) * 180.0 / M_PI;
}

Vector addVectors(const Vector& a, const Vector& b) {
    return {a.x + b.x, a.y + b.y};
}

Vector subtractVectors(const Vector& a, const Vector& b) {
    return {a.x - b.x, a.y - b.y};
}

bool areParallel(const Vector& a, const Vector& b) {
    return (a.x * b.y == a.y * b.x);
}

int main() {
    srand(time(0));
    
    Vector v1 = {rand() % 20 - 10, rand() % 20 - 10};
    Vector v2 = {rand() % 20 - 10, rand() % 20 - 10};
    Vector v3 = {rand() % 20 - 10, rand() % 20 - 10};

    std::cout << "Vectors:" << std::endl;
    std::cout << "v1 = (" << v1.x << ", " << v1.y << ")" << std::endl;
    std::cout << "v2 = (" << v2.x << ", " << v2.y << ")" << std::endl;
    std::cout << "v3 = (" << v3.x << ", " << v3.y << ")" << std::endl;

    std::cout << "\nLengths:" << std::endl;
    std::cout << "Length of v1 = " << vectorLength(v1) << std::endl;
    std::cout << "Length of v2 = " << vectorLength(v2) << std::endl;
    std::cout << "Length of v3 = " << vectorLength(v3) << std::endl;

    std::cout << "\nAngles between vectors:" << std::endl;
    std::cout << "Angle between v1 and v2 = " << angleBetween(v1, v2) << " degrees" << std::endl;
    std::cout << "Angle between v1 and v3 = " << angleBetween(v1, v3) << " degrees" << std::endl;
    std::cout << "Angle between v2 and v3 = " << angleBetween(v2, v3) << " degrees" << std::endl;

    std::cout << "\nVector sums and differences:" << std::endl;
    Vector sum = addVectors(v1, v2);
    Vector diff = subtractVectors(v1, v2);
    std::cout << "v1 + v2 = (" << sum.x << ", " << sum.y << ")" << std::endl;
    std::cout << "v1 - v2 = (" << diff.x << ", " << diff.y << ")" << std::endl;

    sum = addVectors(v1, v3);
    diff = subtractVectors(v1, v3);
    std::cout << "v1 + v3 = (" << sum.x << ", " << sum.y << ")" << std::endl;
    std::cout << "v1 - v3 = (" << diff.x << ", " << diff.y << ")" << std::endl;

    sum = addVectors(v2, v3);
    diff = subtractVectors(v2, v3);
    std::cout << "v2 + v3 = (" << sum.x << ", " << sum.y << ")" << std::endl;
    std::cout << "v2 - v3 = (" << diff.x << ", " << diff.y << ")" << std::endl;

    std::cout << "\nParallel check:" << std::endl;
    std::cout << "v1 and v2 are " << (areParallel(v1, v2) ? "parallel" : "not parallel") << std::endl;
    std::cout << "v1 and v3 are " << (areParallel(v1, v3) ? "parallel" : "not parallel") << std::endl;
    std::cout << "v2 and v3 are " << (areParallel(v2, v3) ? "parallel" : "not parallel") << std::endl;

    return 0;
}
