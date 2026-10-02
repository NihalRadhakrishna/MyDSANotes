// Pascal's triangle: every value is the sum of the two values above it.
// C(i, j) = C(i - 1, j - 1) + C(i - 1, j), with C(i, 0) = C(i, i) = 1.

vector<vector<long long>> C(n + 1, vector<long long>(n + 1));

for (int i = 0; i <= n; i++) {
    C[i][0] = C[i][i] = 1;

    for (int j = 1; j < i; j++) {
        C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

// Time complexity: O(n^2)
// Space complexity: O(n^2)


// nCr under a prime modulus:
// nCr = n! / (r! * (n - r)!)
// Division becomes multiplication by the modular inverse.
// For a prime MOD, inverse(x) = x^(MOD - 2) by Fermat's Little Theorem.

const long long MOD = 1e9 + 7;

long long power(long long a, long long b) {
    long long ans = 1;

    while (b) {
        if (b & 1)
            ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

// Time complexity: O(log MOD)
// Space complexity: O(1)

long long nCr(long long n, long long r) {
    if (r < 0 || r > n)
        return 0;

    long long factN = 1;
    long long factR = 1;
    long long factNR = 1;

    for (int i = 1; i <= n; i++)
        factN = factN * i % MOD;

    for (int i = 1; i <= r; i++)
        factR = factR * i % MOD;

    for (int i = 1; i <= n-r; i++)
        factNR = factNR * i % MOD;

    return factN * power(factR, MOD-2) % MOD
                  * power(factNR, MOD-2) % MOD;
}

// Time complexity: O(n + log MOD)
// Space complexity: O(1)