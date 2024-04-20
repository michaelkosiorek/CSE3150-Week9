#include "triangle.h"


std::ostream& operator<<(std::ostream& os, const Point3d& point3d) {
    double truncated_x = truncate_double(point3d.get_x(), 2);
    double truncated_y = truncate_double(point3d.get_y(), 2);
    double truncated_z = truncate_double(point3d.get_z(), 2);
    os << "(" << truncated_x << ", " << truncated_y << ", " << truncated_z << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
    os << triangle.get_p1() << endl << triangle.get_p2() << endl << triangle.get_p3();
    return os;
}

double truncate_double(double value, int decimal_places) {
    double factor = pow(10.0, decimal_places);
    double truncated = std::floor(value * factor) / factor;
    return truncated;
}

double compute_dist_two_points(const Point3d& p1, const Point3d& p2) {
    return sqrt(pow((p2.get_x() - p1.get_x()), 2) + pow((p2.get_y() - p1.get_y()), 2) + pow((p2.get_z() - p1.get_z()), 2));
}

void Triangle::compute_all_distances() {
    dist_p1_p2 = compute_dist_two_points(p1, p2);
    dist_p1_p3 = compute_dist_two_points(p1, p3);
    dist_p2_p3 = compute_dist_two_points(p2, p3);
}

void Triangle::compute_semi_perimeter() {
    semi_perimeter = (dist_p1_p2 + dist_p1_p3 + dist_p2_p3) / 2.0;
}

void Triangle::compute_area() {
    area = sqrt(semi_perimeter * (semi_perimeter - dist_p1_p2) * (semi_perimeter - dist_p1_p3) * (semi_perimeter - dist_p2_p3));
}

void Triangle::initialize_triangle_info() {
    compute_all_distances();
    compute_semi_perimeter();
    compute_area();
}