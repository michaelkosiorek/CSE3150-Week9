#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "triangle.h"

TEST_CASE("unit testing triangle and p3d") {

    SUBCASE("3d point") {
        Point3d point(1, 2, 3);

        CHECK_EQ(point.get_x(), 1);
        CHECK_EQ(point.get_y(), 2);
        CHECK_EQ(point.get_z(), 3);

        point.set_x(100);
        CHECK_EQ(point.get_x(), 100);
    };

    SUBCASE("empty point") {
        Point3d point;

        CHECK_EQ(point.get_x(), 0);
        CHECK_EQ(point.get_y(), 0);
        CHECK_EQ(point.get_z(), 0);

        point.set_x(1);
        CHECK_EQ(point.get_x(), 1);
    };

    SUBCASE("dist 2 points") {
        Point3d p1(1, 2, 3);
        Point3d p2(10, 11, 12);

        double expected_dist = 15.59;
        double calculated_dist = truncate_double(compute_dist_two_points(p1, p2), 2);

        CHECK_EQ(calculated_dist, expected_dist);
    };

    SUBCASE("dist 2 zero-points") {
        Point3d p1(0, 0, 0);
        Point3d p2(0, 0, 0);

        double expected_dist = 0;
        double calculated_dist = truncate_double(compute_dist_two_points(p1, p2), 2);

        CHECK_EQ(calculated_dist, expected_dist);
    };

    SUBCASE("dist 2 identical-points") {
        Point3d p1(10000, 10000, 10000);
        Point3d p2(10000, 10000, 10000);

        double expected_dist = 0;
        double calculated_dist = truncate_double(compute_dist_two_points(p1, p2), 2);

        CHECK_EQ(calculated_dist, expected_dist);
    };

    SUBCASE("zero'd triangle") {
        Point3d p1, p2, p3;
        Triangle triangle = {p1, p2, p3};

        CHECK_EQ(triangle.get_dist_p1_p2(), 0);
        CHECK_EQ(triangle.get_dist_p1_p3(), 0);
        CHECK_EQ(triangle.get_dist_p2_p3(), 0);
        CHECK_EQ(triangle.get_area(), 0);
        CHECK_EQ(triangle.get_semi_perimeter(), 0);
    };

    SUBCASE("real scenario") {
        Point3d p1(1, 2, 3), p2(11, 12, 13), p3(-11, -12, -13);
        Triangle triangle = {p1, p2, p3};

        //used online calc for expected vals
        double expected_12 = 17.32, expected_13 = 24.41, expected_23 = 41.67;
        double expected_semi_perimeter = 41.70, expected_area = 24.495;

        CHECK_EQ(truncate_double(triangle.get_dist_p1_p2(), 2), expected_12);
        CHECK_EQ(truncate_double(triangle.get_dist_p1_p3(), 2), expected_13);
        CHECK_EQ(truncate_double(triangle.get_dist_p2_p3(), 2), expected_23);
        CHECK_EQ(truncate_double(triangle.get_semi_perimeter(), 2), expected_semi_perimeter);
        CHECK_EQ(truncate_double(triangle.get_area(), 3), expected_area);
    }
}