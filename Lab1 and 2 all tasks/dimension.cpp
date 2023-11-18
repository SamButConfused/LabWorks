#include <iostream>
#include <cmath>

using namespace std;

class Point3D {
private:
    double x, y, z;

public:
    // Constructors
    Point3D() : x(0.0), y(0.0), z(0.0) {}
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    // Getters and setters
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }

    // Distance operator
    friend double operator-(const Point3D& p1, const Point3D& p2) {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        double dz = p1.z - p2.z;
        return sqrt(dx*dx + dy*dy + dz*dz);
    }
};

int main() {
    // Create two objects of Point3D
    Point3D p1;
    Point3D p2(1.0, 2.0, 3.0);

    // Use getters and setters
    p1.setX(4.0);
    p1.setY(5.0);
    p1.setZ(6.0);

    cout << "p1: (" << p1.getX() << ", " << p1.getY() << ", " << p1.getZ() << ")" << endl;
    cout << "p2: (" << p2.getX() << ", " << p2.getY() << ", " << p2.getZ() << ")" << endl;

    // Calculate distance between points
    double distance = p1 - p2;
    cout << "Distance between p1 and p2: " << distance << endl;

    // Change coordinates of p2
    p2.setX(9.0);
    p2.setY(12.0);
    p2.setZ(14.0);

    // Calculate distance again
    distance = p1 - p2;
    cout << "Distance between p1 and updated p2: " << distance << endl;

    return 0;
}
