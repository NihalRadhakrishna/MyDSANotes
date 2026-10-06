// GCD properties:
// 1. gcd(a, b) = gcd(b, a)
// 2. gcd(a, b) = gcd(b, a % b)
// 3. gcd(a, b) = gcd(b, a - b)
// 4. gcd(a, b) = gcd(b, a + b)
// 5. gcd(a, b) = gcd(b, a * b)
// 6. gcd(a, b) = gcd(b, a / b)
// 7. gcd(a, b) = gcd(b, a % b)





#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << gcd(12, 18);
}

// Euclidean algorithm: gcd(a, b) = gcd(b, a % b).
// Each remainder is smaller than the previous divisor, so the loop ends at gcd.
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Time complexity: O(log min(a, b))
// Space complexity: O(1)


// lcm(a, b) * gcd(a, b) = a * b.
// Divide first so the multiplication does not overflow as easily.
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

// Time complexity: O(log min(a, b))
// Space complexity: O(1)