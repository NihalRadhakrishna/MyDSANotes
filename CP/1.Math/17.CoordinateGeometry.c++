// Distance between (x1, y1) and (x2, y2) is sqrt(dx * dx + dy * dy).
// (0, 0) and (3, 4) are 5 apart because 3 * 3 + 4 * 4 = 25.
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

// Compare this value when a problem only asks which distance is larger.
// It keeps the same order as distance and avoids floating-point error.
long long squaredDistance(long long x1, long long y1, long long x2, long long y2) {
    long long dx = x2 - x1;
    long long dy = y2 - y1;
    return dx * dx + dy * dy;
}

// Time complexity: O(1)
// Space complexity: O(1)


// Cross product of vectors (x1, y1) and (x2, y2) is x1 * y2 - y1 * x2.
// Its sign is the turn from the first vector to the second:
// positive means counter-clockwise, negative means clockwise, 0 means collinear.
long long cross(long long x1, long long y1, long long x2, long long y2) {
    return x1 * y2 - y1 * x2;
}

// Orientation of C relative to directed line AB.
// It is the cross product of vectors AB and AC.
// A(0, 0), B(4, 0), C(2, 2): (4 * 2) - (0 * 2) = 8, so C is counter-clockwise.
long long orientation(pair<long long, long long> A,
                      pair<long long, long long> B,
                      pair<long long, long long> C) {
    return cross(B.first - A.first, B.second - A.second,
                 C.first - A.first, C.second - A.second);
}

// Three points lie on one straight line exactly when this cross product is 0.
bool collinear(pair<long long, long long> A,
               pair<long long, long long> B,
               pair<long long, long long> C) {
    return orientation(A, B, C) == 0;
}

// Time complexity: O(1)
// Space complexity: O(1)


// Triangle area is half the absolute value of the same cross product.
// |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| / 2
double triangleArea(pair<long long, long long> A,
                    pair<long long, long long> B,
                    pair<long long, long long> C) {
    return abs(orientation(A, B, C)) / 2.0;
}

// Time complexity: O(1)
// Space complexity: O(1)
