// Binary exponentiation: square the base and halve the exponent.
// When the current bit of b is 1, that power of the base belongs in the answer.
long long power(long long a, long long b) {
    long long ans = 1;

    while (b > 0) {
        if (b % 2 == 1)
            ans *= a;

        a *= a;
        b /= 2;
    }

    return ans;
}

// Time complexity: O(log b)
// Space complexity: O(1)


// Same idea, with every multiplication reduced modulo MOD.
long long power(long long a, long long b, long long MOD) {
    long long ans = 1;

    while (b > 0) {
        if (b & 1)
            ans = (ans * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

// Time complexity: O(log b)
// Space complexity: O(1)