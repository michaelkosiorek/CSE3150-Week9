#include "triangle.h"


int main() {

    double x, y, z;
    cout << "Enter p1 coordinates separated by spaces:" << endl;
    cin >> x >> y >> z; 
    Point3d point3d_1(x, y, z);
    cout << "Entered: (" << x << ", " << y << ", " << z << ")" << endl;
    cout << "Enter p2 coordinates separated by spaces:" << endl;
    cin >> x >> y >> z; 
    Point3d point3d_2(x, y, z);
    cout << "Entered: (" << x << ", " << y << ", " << z << ")" << endl;
    cout << "Enter p3 coordinates separated by spaces:" << endl;
    cin >> x >> y >> z; 
    Point3d point3d_3(x, y, z);
    cout << "Entered: (" << x << ", " << y << ", " << z << ")" << endl;

    Triangle triangle(point3d_1, point3d_2, point3d_3);
    cout << triangle << endl;

    cout << "Dist p1->p2: " << triangle.get_dist_p1_p2() << endl;
    cout << "Dist p1->p3: " << triangle.get_dist_p1_p3() << endl;
    cout << "Dist p2->p3: " << triangle.get_dist_p2_p3() << endl;
    cout << "Semi perimeter: " << triangle.get_semi_perimeter() << endl;
    cout << "Area: " << triangle.get_area() << endl;

    return 0;
}