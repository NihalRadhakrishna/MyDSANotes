// a and inv(a) multiply to 1 under modulo m:
// (a * inv(a)) % m = 1
// An inverse exists only when gcd(a, m) = 1.
// Division under modulo is multiplication by the inverse:
// (a / b) % m = (a * inv(b)) % m


// Fermat's Little Theorem works when m is prime and a is not divisible by m.
// inv(a) = a^(m - 2) % m
const long long MOD = 1e9 + 7;

long long power(long long a, long long b) {
    long long ans = 1;

    // ans starts at 1 because multiplying by 1 does not change the product.
    // a % MOD has the same remainder as a, so the power is unchanged.
    // Example: MOD = 7, a = 10. 10 % 7 = 3, and 10^2 % 7 = 3^2 % 7 = 2.
    // Reducing a first also keeps a * a inside a 64-bit integer.
    // a = 1e18 overflows when squared, while a % MOD does not.
    a %= MOD;

    while (b > 0) {
        if (b & 1)
            ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

long long inverseFermat(long long a) {
    return power(a, MOD - 2);
}

// Time complexity: O(log MOD)
// Space complexity: O(1)


// Extended Euclid works for any modulus, including composite moduli.
// It solves a*x + m*y = gcd(a, m). When the gcd is 1, x is the inverse.
long long extendedGcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long gcd = extendedGcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

long long inverseEuclid(long long a, long long m) {
    long long x, y;
    long long gcd = extendedGcd(a, m, x, y);

    if (gcd != 1)
        return -1;

    return (x % m + m) % m;
}

// Time complexity: O(log min(a, m))
// Space complexity: O(log min(a, m)) for the recursive call stack


// All inverses from 1 to n can be built in one pass when MOD is prime.
// inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD
// This is the usual preprocessing step before many modular divisions.
vector<long long> inverseRange(int n) {
    vector<long long> inv(n + 1);
    inv[1] = 1;

    for (int i = 2; i <= n; i++)
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;

    return inv;
}

// Time complexity: O(n)
// Space complexity: O(n)
