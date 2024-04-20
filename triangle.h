#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <ostream>
#include <cmath>
#include <iostream>


using namespace std;

struct Point3d {
    private:
        double x;
        double y;
        double z;
    public:
        Point3d(){};
        Point3d(const Point3d & p3d) : x(p3d.get_x()), y(p3d.get_y()), z(p3d.get_z()) {};
        Point3d(double x, double y, double z) : x(x), y(y), z(z) {};
        ~Point3d(){};

        //getters
        double get_x() const {return x;}
        double get_y() const {return y;}
        double get_z() const {return z;}
        //setters
        void set_x(double& new_x) {x = new_x;};
        void set_y(double& new_y) {y = new_y;};
        void set_z(double& new_z) {z = new_z;};
};

struct Triangle {
    private:
        Point3d p1;
        Point3d p2;
        Point3d p3;

        double dist_p1_p2;
        double dist_p1_p3;
        double dist_p2_p3;

        double semi_perimeter;
        double area;

        void compute_all_distances();
        void compute_semi_perimeter();
        void compute_area();
        //simply calls all of the above functions for the constructor
        void initialize_triangle_info();
    public:
        Triangle():p1(), p2(), p3() {};
        Triangle(const Point3d& p1, const Point3d& p2, const Point3d& p3) : p1(p1), p2(p2), p3(p3) {
            initialize_triangle_info();
        };
        Triangle(const Triangle& tri) : p1(tri.p1), p2(tri.p2), p3(tri.p3) {
            initialize_triangle_info();
        };
        ~Triangle(){};

        //getters
        Point3d get_p1() const {return p1;}
        Point3d get_p2() const {return p2;}
        Point3d get_p3() const {return p3;}
        double get_area() const {return area;};
        double get_semi_perimeter() const {return semi_perimeter;};
        double get_dist_p1_p2() const {return dist_p1_p2;};
        double get_dist_p1_p3() const {return dist_p1_p3;};
        double get_dist_p2_p3() const {return dist_p2_p3;};

        void recompute() {initialize_triangle_info();};
        /*
        setters/
        you cannot set anything but the points because the info would no longer be true.

        NOTE FOR SETTERS:
            all setters recall the initalization of triangle info,
            because everything like the distances, semi-perimeter, area, etc. MUST
            be updated if even one point is changed.
        */
        void set_p1(Point3d& new_point) {
            p1 = new_point;
            initialize_triangle_info();
        };
        void set_p2(Point3d& new_point) {
            p2 = new_point;
            initialize_triangle_info();
        };
        void set_p3(Point3d& new_point) {
            p3 = new_point;
            initialize_triangle_info();
        };
};

std::ostream& operator<<(std::ostream& os, const Point3d& point3d);
std::ostream& operator<<(std::ostream& os, const Triangle& triangle);

double truncate_double(double value, int decimal_places);
double compute_dist_two_points(const Point3d& p1, const Point3d& p2);

#endif