#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Line {
    double x, y, z;
    double a, b, c; // Direction vector
};

struct Plane {
    double a, b, c, d; // Plane equation: ax + by + cz + d = 0
};

double dotProduct(const Line& l, const Plane& p) {
    return l.a * p.a + l.b * p.b + l.c * p.c;
}

double magnitude(double x, double y, double z) {
    return sqrt(x*x + y*y + z*z);
}

double angleBetween(const Line& l, const Plane& p) {
    double dot = dotProduct(l, p);
    double magL = magnitude(l.a, l.b, l.c);
    double magP = magnitude(p.a, p.b, p.c);
    return asin(dot / (magL * magP)) * 180.0 / M_PI;
}

bool areParallel(const Line& l, const Plane& p) {
    return dotProduct(l, p) == 0;
}

double distanceBetween(const Line& l, const Plane& p) {
    return abs(p.a * l.x + p.b * l.y + p.c * l.z + p.d) / magnitude(p.a, p.b, p.c);
}

bool lineIntersectsPlane(const Line& l, const Plane& p, double& t, double& x, double& y, double& z) {
    double denominator = dotProduct(l, p);
    if (denominator == 0) {
        return false;
    }
    t = -(p.a * l.x + p.b * l.y + p.c * l.z + p.d) / denominator;
    x = l.x + t * l.a;
    y = l.y + t * l.b;
    z = l.z + t * l.c;
    return true;
}

int main() {
    srand(time(0));
    
    Line l = {rand() % 20 - 10, rand() % 20 - 10, rand() % 20 - 10,
              rand() % 20 - 10, rand() % 20 - 10, rand() % 20 - 10};
    Plane p = {rand() % 20 - 10, rand() % 20 - 10, rand() % 20 - 10, rand() % 20 - 10};

    std::cout << "Line:" << std::endl;
    std::cout << "Point on line: (" << l.x << ", " << l.y << ", " << l.z << ")" << std::endl;
    std::cout << "Direction vector: (" << l.a << ", " << l.b << ", " << l.c << ")" << std::endl;

    std::cout << "\nPlane:" << std::endl;
    std::cout << "Plane equation: " << p.a << "x + " << p.b << "y + " << p.c << "z + " << p.d << " = 0" << std::endl;

    std::cout << "\nAngle between line and plane: " << angleBetween(l, p) << " degrees" << std::endl;

    if (areParallel(l, p)) {
        std::cout << "The line and plane are parallel." << std::endl;
        std::cout << "Distance between line and plane: " << distanceBetween(l, p) << std::endl;
    } else {
        std::cout << "The line and plane are not parallel." << std::endl;
        double t, x, y, z;
        if (lineIntersectsPlane(l, p, t, x, y, z)) {
            std::cout << "The line intersects the plane at point: (" << x << ", " << y << ", " << z << ")" << std::endl;
        } else {
            std::cout << "The line does not intersect the plane." << std::endl;
        }
    }

    return 0;
}
