// Euler's totient φ(n) counts integers from 1 to n that are coprime to n.
// φ(n) = n * product over each distinct prime p dividing n of (1 - 1/p).
// Example: 12 = 2^2 * 3, so φ(12) = 12 * (1 - 1/2) * (1 - 1/3) = 4.

int phi(int n) {
    int result = n;

    // Find each distinct prime factor by trial division.
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            // Remove every power of p so this prime is used only once.
            while (n % p == 0)
                n /= p;

            // result = result * (1 - 1/p), computed with integer division.
            result -= result / p;
        }
    }

    // A remaining value greater than 1 is a prime factor larger than sqrt(n).
    if (n > 1)
        result -= result / n;

    return result;
}

// Time complexity: O(sqrt(n))
// Space complexity: O(1)