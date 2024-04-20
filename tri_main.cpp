#include "triangle.h"


int main() {

    double x, y, z;
    cout << "Enter p1 coordinates separated by spaces:" << endl;
    cin >> x >> y >> z; 
    Point3d point3d_1(x, y, z);


    // Use of Point3d ostream operator:


    cout << "Entered: " << point3d_1 << endl;
    cout << "Enter p2 coordinates separated by spaces:" << endl;
    cin >> x >> y >> z; 
    Point3d point3d_2(x, y, z);
    cout << "Entered: " << point3d_2 << endl;
    cout << "Enter p3 coordinates separated by spaces:" << endl;
    cin >> x >> y >> z; 
    Point3d point3d_3(x, y, z);
    cout << "Entered: " << point3d_3 << endl;

    Triangle triangle(point3d_1, point3d_2, point3d_3);


    // Use of Triangle ostream operator:


    cout << "Triangle consists of points:" << endl << triangle << endl << endl;

    cout << "Dist p1->p2: " << truncate_double(triangle.get_dist_p1_p2(), 2) << endl;
    cout << "Dist p1->p3: " << truncate_double(triangle.get_dist_p1_p3(), 2) << endl;
    cout << "Dist p2->p3: " << truncate_double(triangle.get_dist_p2_p3(), 2) << endl;
    cout << "Semi perimeter: " << truncate_double(triangle.get_semi_perimeter(), 3) << endl;
    cout << "Area: " << truncate_double(triangle.get_area(), 3) << endl;

    return 0;
}