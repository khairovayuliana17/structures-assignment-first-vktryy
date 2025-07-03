
// declare Point structure here
struct Point {
    // your code here
    double x = 0.0;
    double y = 0.0;
};

// declare Circle structure here
struct Circle {
    // your code here ("center" and "radius" (look for expected names in test.cpp))
    Point center;
    double radius = 0.0;
};
double circleArea(Circle c);
double circleLength(Circle c);
bool isPointInside(Circle c, Point p);
