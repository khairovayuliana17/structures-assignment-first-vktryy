#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>

#include "circle.h"

static_assert(
    std::is_same_v<decltype(Circle::center), Point>, "Circle::center must be of type Point");
static_assert(
    std::is_same_v<decltype(Circle::radius), double>, "Circle::radius must be of type double");

TEST_CASE("Circle: Initialization with zeros by default") {
    Circle c;
    REQUIRE(std::abs(c.center.x) < 1e-9);
    REQUIRE(std::abs(c.center.y) < 1e-9);
    REQUIRE(std::abs(c.radius) < 1e-9);
}

TEST_CASE("Circle area calculation") {
    Circle c{{0.0, 0.0}, 5.0};
    double area = circleArea(c);
    REQUIRE(area == Approx(78.5398163397).epsilon(1e-9));
}

TEST_CASE("Circle length calculation") {
    Circle c{{1.0, 2.0}, 3.0};
    double length = circleLength(c);
    REQUIRE(length == Approx(18.8495559215).epsilon(1e-9));
}

TEST_CASE("Point inside circle: positive case") {
    Circle c{{2.0, 3.0}, 4.0};
    Point p{3.0, 4.0};
    bool inside = isPointInside(c, p);
    REQUIRE(inside == true);
}

TEST_CASE("Point inside circle: negative case") {
    Circle c{{-1.0, -1.0}, 2.0};
    Point p{1.0, 1.0};
    bool inside = isPointInside(c, p);
    REQUIRE(inside == false);
}

TEST_CASE("Point inside circle: edge case") {
    Circle c{{0.0, 0.0}, 5.0};
    Point p{3.0, 4.0};
    bool inside = isPointInside(c, p);
    REQUIRE(inside == true);
}

TEST_CASE("Circle area: zero radius") {
    Circle c{{1.0, 1.0}, 0.0};
    double area = circleArea(c);
    REQUIRE(area == Approx(0.0).epsilon(1e-9));
}

TEST_CASE("Circle length: zero radius") {
    Circle c{{2.0, 2.0}, 0.0};
    double length = circleLength(c);
    REQUIRE(length == Approx(0.0).epsilon(1e-9));
}

TEST_CASE("Point inside circle: zero radius") {
    Circle c{{3.0, 4.0}, 0.0};
    Point p{3.0, 4.0};
    bool inside = isPointInside(c, p);
    REQUIRE(inside == true);  // Точка совпадает с центром
}

TEST_CASE("Point inside circle: negative coordinates") {
    Circle c{{-2.0, -3.0}, 5.0};
    Point p{-1.0, -1.0};
    bool inside = isPointInside(c, p);
    REQUIRE(inside == true);
}

TEST_CASE("Circle area: large radius") {
    Circle c{{0.0, 0.0}, 1e6};
    double area = circleArea(c);
    REQUIRE(area == Approx(3.14159265358979e12).epsilon(1e-3));
}
