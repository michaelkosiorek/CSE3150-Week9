#include "triangle.h"


int main() {

    

    Point3d point3d_1 = {10.32321, 1.3232, .3};
    Point3d point3d_2 = {11.32321, 3.3232, 3.3};
    Point3d point3d_3 = {0.32321, 4.3232, 10.3};

    cout << point3d_1 << endl;
    cout << endl;
    Triangle triangle(point3d_1, point3d_2, point3d_3);
    cout << triangle << endl;

    cout << "Dist p1->p2: " << triangle.get_dist_p1_p2() << endl;
    cout << "Dist p1->p3: " << triangle.get_dist_p1_p3() << endl;
    cout << "Dist p2->p3: " << triangle.get_dist_p2_p3() << endl;
    cout << "Semi perimeter: " << triangle.get_semi_perimeter() << endl;
    cout << "Area: " << triangle.get_area() << endl;

    return 0;
}