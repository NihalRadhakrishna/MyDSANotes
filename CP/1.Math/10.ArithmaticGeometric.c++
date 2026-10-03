// Arithmetic progression: a, a + d, a + 2d, ...
// nth term: a + (n - 1) * d
long long nthAP(long long a, long long d, long long n) {
    return a + (n - 1) * d;
}

// Sum of the first n terms: n / 2 * (2a + (n - 1) * d)
// This is also n / 2 * (first + last).
long long sumAP(long long a, long long d, long long n) {
    return n * (2 * a + (n - 1) * d) / 2;
}

// Time complexity: O(1)
// Space complexity: O(1)


// Sum of integers from L to R is an AP with difference 1.
// count = R - L + 1, and the two ends are L and R.
// Divide the even value first so the product does not overflow as easily.
long long sumRange(long long L, long long R) {
    long long count = R - L + 1;
    long long ends = L + R;

    if (count % 2 == 0)
        return (count / 2) * ends;

    return count * (ends / 2);
}

// Time complexity: O(1)
// Space complexity: O(1)


// Numbers from L to R that are divisible by k also form an AP.
// The first term is the smallest multiple of k that is >= L.
long long countMultiples(long long L, long long R, long long k) {
    long long first = ((L + k - 1) / k) * k;
    long long last = (R / k) * k;

    if (first > R)
        return 0;

    return (last - first) / k + 1;
}

// Time complexity: O(1)
// Space complexity: O(1)


// Geometric progression: a, a*r, a*r^2, ...
// nth term: a * r^(n - 1)
// Sum: a * (r^n - 1) / (r - 1), when r != 1
// If r == 1, every term is a, so the sum is a * n.
long long sumGP(long long a, long long r, long long n) {
    if (r == 1)
        return a * n;

    long long power = 1;

    for (long long i = 0; i < n; i++)
        power *= r;

    return a * (power - 1) / (r - 1);
}

// Time complexity: O(n)
// Space complexity: O(1)


// Contest problems usually ask for the GP sum modulo a prime, often 1e9 + 7.
// Division by (r - 1) becomes multiplication by its modular inverse.
// For a prime MOD, inverse(x) = x^(MOD - 2).
const long long MOD = 1e9 + 7;

long long power(long long a, long long b) {
    long long ans = 1;
    a %= MOD;

    while (b > 0) {
        if (b & 1)
            ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

long long sumGPMod(long long a, long long r, long long n) {
    a %= MOD;
    r %= MOD;

    if (r == 1)
        return a * (n % MOD) % MOD;

    long long numerator = (power(r, n) - 1 + MOD) % MOD;
    long long inverse = power(r - 1 + MOD, MOD - 2);

    return a * numerator % MOD * inverse % MOD;
}

// Time complexity: O(log n)
// Space complexity: O(1)
