// A linear Diophantine equation asks for integers x and y such that
// a*x + b*y = c.
// A solution exists exactly when gcd(a, b) divides c.
//
// 6x + 10y = 15 has no integer solution because gcd(6, 10) = 2
// and 2 does not divide 15.
// 15x + 21y = 6 does, because gcd(15, 21) = 3 and 3 divides 6.


// Extended Euclid solves a*x + b*y = gcd(a, b).
long long extendedGcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long g = extendedGcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Multiply the gcd solution by c / gcd to solve a*x + b*y = c.
// For 3x + 5y = 7 this returns x = 14, y = -7, because 3*14 + 5*(-7) = 7.
bool findSolution(long long a, long long b, long long c,
                   long long &x, long long &y) {
    long long g = extendedGcd(a, b, x, y);

    if (g < 0) {
        g = -g;
        x = -x;
        y = -y;
    }

    if (c % g != 0)
        return false;

    x *= c / g;
    y *= c / g;
    return true;
}

// Time complexity: O(log min(|a|, |b|))
// Space complexity: O(log min(|a|, |b|)) for the recursive call stack


// If (x0, y0) is one solution and g = gcd(a, b), every integer t gives another:
// x = x0 + (b / g) * t
// y = y0 - (a / g) * t
//
// From (14, -7) for 3x + 5y = 7, t = -3 gives
// x = 14 + 5*(-3) = -1
// y = -7 - 3*(-3) = 2
// and 3*(-1) + 5*2 = 7.
void shiftSolution(long long &x, long long &y,
                    long long a, long long b, long long g, long long t) {
    x += (b / g) * t;
    y -= (a / g) * t;
}

// Time complexity: O(1)
// Space complexity: O(1)
